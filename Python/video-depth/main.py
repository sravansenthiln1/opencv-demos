#
# Video depth estimation in OpenCV
#

import cv2 as cv
import numpy as np
import sys
import time

# Set the sample video as the input source
capture_l = cv.VideoCapture("./stereo_l.mp4")
capture_r = cv.VideoCapture("./stereo_r.mp4")

# Create a window to view the video
cv.namedWindow('opencv-demos', cv.WINDOW_NORMAL)
cv.namedWindow('left', cv.WINDOW_NORMAL)
cv.namedWindow('right', cv.WINDOW_NORMAL)

stereo = cv.StereoBM_create(numDisparities=16, blockSize=15)

# Preview the original video
for _ in range(200):
    ret, frame_l = capture_l.read()
    ret, frame_r = capture_r.read()

    frame_l = cv.resize(frame_l, (256, 192))
    frame_r = cv.resize(frame_r, (256, 192))

    frame_l = cv.cvtColor(frame_l, cv.COLOR_BGR2GRAY)
    frame_r = cv.cvtColor(frame_r, cv.COLOR_BGR2GRAY)

    disparity = stereo.compute(frame_l, frame_r)

    if disparity is None:
        continue

    # Normalize the depth map
    normalized_disparity = cv.normalize(disparity, None, 0, 255, cv.NORM_MINMAX)

    # Map the depth to a colormap
    disparity_colormap = cv.applyColorMap(np.uint8(normalized_disparity), cv.COLORMAP_VIRIDIS)

    cv.imshow('left', frame_l)
    cv.imshow('right', frame_r)
    cv.imshow('opencv-demos', disparity_colormap)
    cv.waitKey(30)

# Close all windows and release handles
capture_l.release()
capture_r.release()
cv.destroyAllWindows()
