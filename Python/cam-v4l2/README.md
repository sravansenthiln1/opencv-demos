# Camera Capture with V4L2

### Run the example:
```bash
python3 main.py /dev/videoX
```

Note: You will need to modify the capture parameters of the example depending on your device.

As mentioned by this section

```py
# Capture Parameters
width = 3840
height = 2160
camera_format = cv.VideoWriter_fourcc('U', 'Y', 'V', 'Y')
```

| Device | Height/Width | Format | Device |
| --- | --- | --- | --- |
| VIM3 | 1920x1080 | RGB <br/> (`cv2.VideoWriter_fourcc(*'XVID')`) | `/dev/video0` |
| VIM4 | 3840x2160 | NV12 <br/> (`cv.VideoWriter_fourcc('U', 'Y', 'V', 'Y')`) | `/dev/video50` | 
| Edge2 | 3840x2160 | NV12 <br/> (`cv.VideoWriter_fourcc('U', 'Y', 'V', 'Y')`) | `/dev/video24` (CAM2) <br> `/dev/video33` (CAM1) <br> `/dev/video42` (CAM3) | 
