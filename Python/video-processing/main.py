#
# Video Processing in OpenCV
#

import cv2 as cv
import numpy as np
import sys

# Create various image processing kernels

sharpen_kernel = np.array([[0, -1, 0],
                           [-1, 5, -1],
                           [0, -1, 0]])

edge_kernel = np.array([[-1, -1, -1],
                        [-1, 8, -1],
                        [-1, -1, -1]])

# Set the sample video as the input source
capture = cv.VideoCapture("./video.mp4")

# Create a window to view the video
cv.namedWindow('opencv-demos', cv.WINDOW_NORMAL)

# Preview the original video
for _ in range(500):
    ret, frame = capture.read()

    if not ret or frame is None:
        break

    cv.imshow('opencv-demos', frame)
    cv.waitKey(0)

# View the video with a sharpening kernel applied
for _ in range(100):
    ret, frame = capture.read()

    if not ret or frame is None:
        break

    sharpened_image = cv.filter2D(frame, -1, sharpen_kernel)

    cv.imshow('opencv-demos', sharpened_image)
    cv.waitKey(30)

# View the video with a edge detection kernel applied
for _ in range(100):
    ret, frame = capture.read()

    if not ret or frame is None:
        break

    edge_image = cv.filter2D(frame, -1, edge_kernel)

    cv.imshow('opencv-demos', edge_image)
    cv.waitKey(30)

# Close all windows and release handles
capture.release()
cv.destroyAllWindows()
