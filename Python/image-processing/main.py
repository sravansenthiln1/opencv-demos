#
# Image Processing in OpenCV
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

blur_kernel = 1/25 * np.array([[1, 1, 1, 1, 1],
                               [1, 1, 1, 1, 1],
                               [1, 1, 1, 1, 1],
                               [1, 1, 1, 1, 1],
                               [1, 1, 1, 1, 1]])

vblur_kernel = 1/5 * np.array([[0, 0, 1, 0, 0],
                               [0, 0, 1, 0, 0],
                               [0, 0, 1, 0, 0],
                               [0, 0, 1, 0, 0],
                               [0, 0, 1, 0, 0]])

hblur_kernel = 1/5 * np.array([[0, 0, 0, 0, 0],
                               [0, 0, 0, 0, 0],
                               [1, 1, 1, 1, 1],
                               [0, 0, 0, 0, 0],
                               [0, 0, 0, 0, 0]])

# Read the sample image
image = cv.imread('./sample.png')

# Display the image for 2000 ms (or) 2 seconds.
cv.imshow('opencv-demos', image)
cv.waitKey(2000)

# Color examples

# Grayscale conversion of Image
grayscale = cv.cvtColor(image, cv.COLOR_BGR2GRAY)
cv.imshow('opencv-demos', grayscale)
cv.waitKey(2000)

# Image color channel extraction
green_channel = image.copy()
green_channel[:,:,0] = 0
green_channel[:,:,2] = 0

cv.imshow('opencv-demos', green_channel)
cv.waitKey(2000)

# Filter examples

# Image sharpening
sharpened_image = cv.filter2D(image, -1, sharpen_kernel)

cv.imshow('opencv-demos', sharpened_image)
cv.waitKey(2000)

# Image edge detection
edge_image = cv.filter2D(image, -1, edge_kernel)

cv.imshow('opencv-demos', edge_image)
cv.waitKey(2000)

# Image blurring
blurred_image = cv.filter2D(image, -1, blur_kernel)

cv.imshow('opencv-demos', blurred_image)
cv.waitKey(2000)

# Image vertical motion blur
vblurred_image = cv.filter2D(image, -1, vblur_kernel)

cv.imshow('opencv-demos', vblurred_image)
cv.waitKey(2000)

# Image horizontal motion blur
hblurred_image = cv.filter2D(image, -1, hblur_kernel)

cv.imshow('opencv-demos', hblurred_image)
cv.waitKey(2000)

# Close all windows
cv.destroyAllWindows()
