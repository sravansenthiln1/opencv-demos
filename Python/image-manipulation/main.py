#
# Image Manipulation in OpenCV
#

import cv2 as cv
import numpy as np
import sys

# Read the sample image
image = cv.imread('./sample.png')

# Display the image for 2000 ms (or) 2 seconds.
cv.imshow('opencv-demos', image)
cv.waitKey(2000)

# Print the shape of the image,
print("Height: ", image.shape[0])
print("Width: ", image.shape[1])
print("Color Channels: ", image.shape[2])

# Draw a line on the image, between point (0, 0) and (255, 255), 
# with Blue in BGR color, and a line thickness of 5px
cv.line(image, (0, 0), (255, 255), (255, 0, 0), 5)

cv.imshow('opencv-demos', image)
cv.waitKey(2000)

# Draw a rectangle on the image, provided the top left and bottom right corner 
# with White in BGR color.
cv.rectangle(image, (0, 0), (127, 127), (255, 255, 255), 2)

cv.imshow('opencv-demos', image)
cv.waitKey(2000)

# Draw a filled rectangle on the image with Green in BGR color.
cv.rectangle(image, (0, 180), (255, 255), (0, 255, 0), -1)

cv.imshow('opencv-demos', image)
cv.waitKey(2000)

# Write "hello" on the image in white text
cv.putText(image, 'OpenCV', (10, 200), cv.FONT_HERSHEY_SIMPLEX, 0.5, (255, 255, 255), 1, cv.LINE_AA)

cv.imshow('opencv-demos', image)
cv.waitKey(2000)

# Save the image as output image
cv.imwrite('./output.png', image)

# Close all windows
cv.destroyAllWindows()
