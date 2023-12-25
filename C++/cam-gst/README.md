# Camera Capture with GStreamer

### Run the example:
```bash
make
./main /dev/videoX
```

Note: You will need to modify the capture parameters of the example depending on your device.

As mentioned by this section

```c++
// Capture Parameters
std::string width = "3840";
std::string height = "2160";
std::string fps = "30";
std::string camera_format = "NV12";
```

| Device | Height/Width | Format | Device |
| --- | --- | --- | --- |
| VIM3 | 1920x1080 | RGB <br/> (`cv::VideoWriter::fourcc('X', 'V', 'I', 'D')`) | `/dev/video0` |
| VIM4 | 3840x2160 | NV12 <br/> (`cv::VideoWriter::fourcc('U', 'Y', 'V', 'Y')`) | `/dev/video50` | 
| Edge2 | 3840x2160 | NV12 <br/> (`cv::VideoWriter::fourcc('U', 'Y', 'V', 'Y')`) | `/dev/video24` (CAM2) <br> `/dev/video33` (CAM1) <br> `/dev/video42` (CAM3) | 
