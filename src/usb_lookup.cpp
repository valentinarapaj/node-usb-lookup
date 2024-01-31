#include <napi.h>
#include <libusb-1.0/libusb.h>
#include <iomanip>
#include <sstream>

Napi::Value GetUSBDeviceInfo(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    libusb_context* ctx = NULL;
    libusb_init(&ctx);

    libusb_device** list;
    ssize_t count = libusb_get_device_list(ctx, &list);
    if (count < 0) {
        Napi::TypeError::New(env, "Failed to get USB device list").ThrowAsJavaScriptException();
        return env.Undefined();
    }

    Napi::Array usbDevices = Napi::Array::New(env);

    for (ssize_t i = 0; i < count; ++i) {
        libusb_device* device = list[i];
        libusb_device_descriptor desc;
        libusb_get_device_descriptor(device, &desc);

        libusb_device_handle* handle;
        if (libusb_open(device, &handle) != LIBUSB_SUCCESS) {
            continue;
        }

        char manufacturer[256], product[256];
        libusb_get_string_descriptor_ascii(handle, desc.iManufacturer, (unsigned char*)manufacturer, sizeof(manufacturer));
        libusb_get_string_descriptor_ascii(handle, desc.iProduct, (unsigned char*)product, sizeof(product));

        std::stringstream vendorIdStream, productIdStream;
        vendorIdStream << "0x" << std::hex << std::setw(4) << std::setfill('0') << desc.idVendor;
        productIdStream << "0x" << std::hex << std::setw(4) << std::setfill('0') << desc.idProduct;


        Napi::Object deviceInfo = Napi::Object::New(env);
        deviceInfo.Set("name", Napi::String::New(env, product));
        deviceInfo.Set("manufacturer", Napi::String::New(env, manufacturer));
        deviceInfo.Set("vendorId", Napi::String::New(env, vendorIdStream.str()));
        deviceInfo.Set("productId", Napi::String::New(env, productIdStream.str()));

        usbDevices.Set(i, deviceInfo);

        libusb_close(handle);
    }

    libusb_free_device_list(list, 1);
    libusb_exit(ctx);

    return usbDevices;
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set("getUSBDeviceInfo", Napi::Function::New(env, GetUSBDeviceInfo));
    return exports;
}

NODE_API_MODULE(usb_lookup, Init)
