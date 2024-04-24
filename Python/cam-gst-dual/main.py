#
# Dual video capture in OpenCV with GStreamer
#

import cv2 as cv
import numpy as np
import sys

# get the first video device node
camera_arg_1 = sys.argv[1]

# get the second video device node
camera_arg_2 = sys.argv[2]

# Capture Parameters
width = "3840"
height = "2160"
fps = "30"
camera_format = "NV12"

# Construct the GStreamer pipeline for the video source
gst_1 = f'v4l2src device={camera_arg_1} ! video/x-raw,format={camera_format},width={width},height={height},framerate={fps}/1 ! videoconvert ! appsink'
gst_2 = f'v4l2src device={camera_arg_2} ! video/x-raw,format={camera_format},width={width},height={height},framerate={fps}/1 ! videoconvert ! appsink'

# Select GStreamer for video capture
capture_1 = cv.VideoCapture(gst_1, cv.CAP_GSTREAMER)
capture_2 = cv.VideoCapture(gst_2, cv.CAP_GSTREAMER)

# Create a window to view the video
cv.namedWindow("video device 1", cv.WINDOW_NORMAL)
cv.namedWindow("video device 2", cv.WINDOW_NORMAL)

# Preview 100 Video frames at ~30 Frames per second
for _ in range(100):
    ret, frame_1 = capture_1.read()
    ret, frame_2 = capture_2.read()

    if not ret or frame_1 is None or frame_2 is None:
        break

    cv.imshow("video device 1", frame_1)
    cv.imshow("video device 2", frame_2)
    cv.waitKey(30)

capture_1.release()
capture_2.release()
cv.destroyAllWindows()
