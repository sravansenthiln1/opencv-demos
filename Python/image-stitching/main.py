#
# Image stitching in OpenCV
#

import cv2 as cv
import numpy as np
import sys

images = []

# Append the sample images
images.append(cv.resize(cv.imread('./image_l.png'), (256, 192)))
images.append(cv.resize(cv.imread('./image_r.png'), (256, 192)))

images = np.array(images)

# Create a object from the stitcher class
stitcher = cv.Stitcher.create()

# Stitch the images together
(status, stitched) = stitcher.stitch(images)

# Display the stiched image
cv.imshow('opencv-demos', stitched)
cv.waitKey(2000)

# Save the stitched image output.
cv.imwrite('stitched_image.png', stitched)

# Close all windows
cv.destroyAllWindows()
