# usb-lookup

`usb-lookup` is a Node.js library that provides a simple interface to retrieve information about connected USB devices on your system. It utilizes the libusb library to interact with USB devices and fetches details such as device name, manufacturer, vendor ID, and product ID.

## Installation

You can install `usb-lookup` via npm:
```bash
npm install usb-lookup
```

## API

### getUSBDeviceInfo()

Returns an array of objects, each representing a connected USB device. Each object has the following properties:

- **name:** The name or of the USB device.
- **manufacturer:** The manufacturer of the USB device.
- **vendorId:** The vendor ID of the USB device.
- **productId:** The product ID of the USB device.

## Example

Here's a simple example of how to use `usb-lookup`:
```javascript
const usbLookup = require('usb-lookup');

// Get USB device information
const devices = usbLookup.getUSBDeviceInfo();

devices.forEach(device => {
    console.log('Name:', device.name);
    console.log('Manufacturer:', device.manufacturer);
    console.log('Vendor ID:', device.vendorId);
    console.log('Product ID:', device.productId);
    console.log('--------------------------');
});
```
## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Acknowledgments

- This module utilizes the **libusb** library for interacting with USB devices.

## Contributing

Contributions are welcome! Please feel free to submit a pull request or open an issue if you find any problems or have suggestions for improvement.
