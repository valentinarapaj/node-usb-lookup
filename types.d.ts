declare module 'usb-lookup' {
    /**
     * Represents information about a USB device.
     */
    type USBDeviceInfo = {
        /** The name or description of the USB device. */
        name: string;
        /** The manufacturer of the USB device. */
        manufacturer: string;
        /** The vendor ID of the USB device. */
        vendorId: string;
        /** The product ID of the USB device. */
        productId: string;
    };

    /**
     * Retrieves information about connected USB devices.
     * @returns An array of USBDeviceInfo objects, each representing a connected USB device.
     */
    function getUSBDeviceInfo(): USBDeviceInfo[];

    export {
        getUSBDeviceInfo
    };
}
