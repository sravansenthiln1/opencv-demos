#
# Image Perspective De-Warping in OpenCV
#

import cv2 as cv
import numpy as np
import sys

# Read the sample image
image = cv.imread("./sample.png")

# Preview the image
cv.imshow('opencv-demos', image)
cv.waitKey(2000)

# Create the arrays of points of the warped object
tl = np.array((116, 92))
tr = np.array((308, 144))
br = np.array((236, 416))
bl = np.array((42, 364))

# Annotate circles on each corner of the image
annotated_image = cv.circle(image.copy(), tl, 5, (24, 167, 254), 2, -1)
annotated_image = cv.circle(annotated_image, tr, 5, (24, 167, 254), 2, -1)
annotated_image = cv.circle(annotated_image, br, 5, (24, 167, 254), 2, -1)
annotated_image = cv.circle(annotated_image, bl, 5, (24, 167, 254), 2, -1)

# Preview the image with the corner points
cv.imshow('opencv-demos', annotated_image)
cv.waitKey(2000)

corners = np.array([tl, tr, br, bl], dtype=np.float32)

x1 = np.linalg.norm(br - bl)
x2 = np.linalg.norm(tr - tl)

y1 = np.linalg.norm(tr - br)
y2 = np.linalg.norm(tl - bl)

w = max(int(x1), int(x2))
h = max(int(y1), int(y2))

dst = np.array([
	[0, 0],
	[w - 1, 0],
	[w - 1, h - 1],
	[0, h - 1]], dtype = "float32")

# Calculate the transformation matrix
M = cv.getPerspectiveTransform(corners, dst)

# Transform the image
warp = cv.warpPerspective(image, M, (w, h))

# Show the image from the correct perspective
cv.imshow('opencv-demos', warp)
cv.waitKey(2000)

# Save the image as output image
cv.imwrite('./output.png', image)

# Close all windows
cv.destroyAllWindows()
