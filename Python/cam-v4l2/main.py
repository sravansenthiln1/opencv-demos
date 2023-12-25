#
# Video capture in OpenCV with V4L2
#

import cv2 as cv
import numpy as np
import sys

# get the video device node
camera_arg = sys.argv[1][10:]

# Capture Parameters
width = 3840
height = 2160
camera_format = cv.VideoWriter_fourcc('U', 'Y', 'V', 'Y')

# Select v4l2 for video capture
capture = cv.VideoCapture(int(camera_arg), cv.CAP_V4L2)

# Configure video format and Resolution
capture.set(cv.CAP_PROP_FOURCC, camera_format)
capture.set(cv.CAP_PROP_FRAME_WIDTH, width)
capture.set(cv.CAP_PROP_FRAME_HEIGHT, height)

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
