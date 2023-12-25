#
# Video capture in OpenCV with GStreamer
#

import cv2 as cv
import numpy as np
import sys

# Get the video device node
camera_arg = sys.argv[1][10:]

# Capture Parameters
width = "3840"
height = "2160"
fps = "30"
camera_format = "NV12"

# Construct the GStreamer pipeline for the video source
gst = f'v4l2src device={camera_arg} ! video/x-raw,format={camera_format},width={width},height={height},framerate={fps}/1 ! ! videoconvert ! appsink'

# Select v4l2 for video capture
capture = cv.VideoCapture(gst, cv.CAP_GSTREAMER)

# Create a window to view the video
cv.namedWindow("video", cv.WINDOW_NORMAL)

# Preview 100 Video frames at ~30 Frames per second
for _ in range(100):
    ret, frame = capture.read()

    if not ret or frame is None:
        break

    cv.imshow("video", frame)
    cv.waitKey(30)

capture.release()
cv.destroyAllWindows()
