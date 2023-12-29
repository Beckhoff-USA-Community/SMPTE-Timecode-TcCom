# About This Repository
This sample is created by [Beckhoff Automation LLC.](https://www.beckhoff.com/en-us/), and is provided as-is under the Zero-Clause BSD license.

This project includes source code to compile your own SMPTE Timecode receiver in TwinCAT C++. Refer to the [application note](https://www.beckhoff.com/media/downloads/application-reports-downloads/2013/dk9222-0213-0063-2.pdf) on how the SMPTE timecode signal is decoded. There is already an [existing PLC implementation](https://download.beckhoff.com/download/document/Application_Notes/DK9222-0213-0063_TwinCAT_sample.zip) that is documented within the application note.

This C++ version allows the Timecode receiver code to be distributed as a TcCom. There are also significant performance advantages due to C++ based decoding and structured exception handling.



# How to get support

Should you have any questions regarding the provided sample code, please contact your local Beckhoff support team. Contact information can be found on the official Beckhoff website at https://www.beckhoff.com/en-us/support/.



## Requirements

- [TE1000 TwinCAT 3 Engineering](https://www.beckhoff.com/en-en/products/automation/twincat/te1xxx-twincat-3-engineering/te1000.html) version 3.1.4024.0 or higher
- TwinCAT XAR version >= 3.1.4024.0
- Visual Studio Professional 2019 with C++ Compilers 
- EL3702 Oversampling terminal
