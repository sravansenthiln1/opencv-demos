#
# Video Perspective De-Warping in OpenCV
#

import cv2 as cv
import numpy as np
import sys

# Set the sample video as the input source
capture = cv.VideoCapture("./video.mp4")

# Create the arrays of points of the warped object
tl = np.array((200, 205))
tr = np.array((278, 205))
br = np.array((378, 284))
bl = np.array((90, 284))

corners = np.array([tl, tr, br, bl], dtype=np.float32)

# Calculate the size of the output image
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

# Create a window to view the video
cv.namedWindow('Original', cv.WINDOW_NORMAL)
cv.namedWindow('Perspective Corrected', cv.WINDOW_NORMAL)

for _ in range(250):
    ret, frame = capture.read()

    if not ret or frame is None:
        break

    # Annotate circles on each corner of the frame
    annotated_frame = cv.circle(frame.copy(), tl, 5, (24, 167, 254), 2, -1)
    annotated_frame = cv.circle(annotated_frame, tr, 5, (24, 167, 254), 2, -1)
    annotated_frame = cv.circle(annotated_frame, br, 5, (24, 167, 254), 2, -1)
    annotated_frame = cv.circle(annotated_frame, bl, 5, (24, 167, 254), 2, -1)

    # Apply the perspective correction
    warp = cv.warpPerspective(frame, M, (w, h))

    # Show the original and corrected video
    cv.imshow('Original', annotated_frame)
    cv.imshow('Perspective Corrected', warp)
    cv.waitKey(30)

# Close all windows and release handles
capture.release()
cv.destroyAllWindows()
