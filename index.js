const usbDeviceInfo = require('./build/Release/usb-lookup');

function getUSBDeviceInfo() {
    return usbDeviceInfo.getUSBDeviceInfo();
}

module.exports = {
    getUSBDeviceInfo
};
