#
# Image depth estimation in OpenCV
#

import cv2 as cv
import numpy as np
import sys

# Append the sample images
image_l = cv.imread('./stereo_l.png', cv.IMREAD_GRAYSCALE)
image_r = cv.imread('./stereo_r.png', cv.IMREAD_GRAYSCALE)

# Create a object from the Stereo CLass
stereo = cv.StereoBM.create(numDisparities=16, blockSize=15)

# Calculate the depth map
disparity = stereo.compute(image_l, image_r)

# Normalize the depth map
normalized_disparity = cv.normalize(disparity, None, 0, 255, cv.NORM_MINMAX)

# Map the depth to a colormap
disparity_colormap = cv.applyColorMap(np.uint8(normalized_disparity), cv.COLORMAP_VIRIDIS)

# Display the stiched image
cv.imshow('opencv-demos', disparity_colormap)
cv.waitKey(5000)

# Close all windows
cv.destroyAllWindows()
