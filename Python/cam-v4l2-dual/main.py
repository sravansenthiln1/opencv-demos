#
# Dual video capture in OpenCV with V4L2
#

import cv2 as cv
import numpy as np
import sys

# get the first video device node
camera_arg_1 = sys.argv[1][10:]

# get the second video device node
camera_arg_2 = sys.argv[2][10:]

# Select v4l2 for video capture
capture_1 = cv.VideoCapture(int(camera_arg_1), cv.CAP_V4L2)
capture_2 = cv.VideoCapture(int(camera_arg_2), cv.CAP_V4L2)

# Configure video format (NV12) and Resolution (3840x2160)
capture_1.set(cv.CAP_PROP_FOURCC, cv.VideoWriter_fourcc('U', 'Y', 'V', 'Y'))
capture_1.set(cv.CAP_PROP_FRAME_WIDTH, 3840)
capture_1.set(cv.CAP_PROP_FRAME_HEIGHT, 2160)

capture_2.set(cv.CAP_PROP_FOURCC, cv.VideoWriter_fourcc('U', 'Y', 'V', 'Y'))
capture_2.set(cv.CAP_PROP_FRAME_WIDTH, 3840)
capture_2.set(cv.CAP_PROP_FRAME_HEIGHT, 2160)


cv.namedWindow("video 1", cv.WINDOW_NORMAL)
cv.namedWindow("video 2", cv.WINDOW_NORMAL)

# Preview 100 Video frames at ~30 Frames per second
for _ in range(100):
    ret, frame_1 = capture_1.read()
    ret, frame_2 = capture_2.read()

    if not ret or frame_1 is None or frame_2 is None:
        break

    cv.imshow("video 1", frame_1)
    cv.imshow("video 2", frame_2)
    cv.waitKey(30)

capture_1.release()
capture_2.release()
cv.destroyAllWindows()
