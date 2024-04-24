# Camera Capture with GStreamer

### Run the example:
```bash
python3 main.py /dev/videoX
```

Note: You will need to modify the capture parameters of the example depending on your device.

As mentioned by this section

```py
# Capture Parameters
width = "3840"
height = "2160"
fps = "30"
camera_format = "NV12"
```

### Device Nodes
| Device | Height x Width | Format | Device |
| --- | --- | --- | --- |
| VIM3 - kernel 4.9 | 1920 x 1080 | RGB | `/dev/video0` |
| VIM3 - kernel 5.15 | 1920 x 1080 | NV12 | `/dev/video50` |
| VIM4 | 3840 x 2160 | NV12  | `/dev/video50` | 
| Edge2 - kernel 5.10.66 | 3840 x 2160 | NV12 | `/dev/video33` (CAM1) <br> `/dev/video24` (CAM2) <br> `/dev/video42` (CAM3) | 
| Edge2 - kernel 5.10.160 and above | 3840 x 2160 | NV12 | `/dev/video42` (CAM1) <br> `/dev/video33` (CAM2) <br> `/dev/video51` (CAM3) | 
