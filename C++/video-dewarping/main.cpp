#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int main() {
    // Set the sample video as the input source
    cv::VideoCapture capture("./video.mp4");

    // Check if the video capture is successful
    if (!capture.isOpened()) {
        std::cout << "Error opening video capture." << std::endl;
        return 1;
    }

    // Create the arrays of points of the warped object
    cv::Point2f tl(200, 205);
    cv::Point2f tr(278, 205);
    cv::Point2f br(378, 284);
    cv::Point2f bl(90, 284);

    std::vector<cv::Point2f> corners = {tl, tr, br, bl};

    // Calculate the size of the output image
    float x1 = cv::norm(br - bl);
    float x2 = cv::norm(tr - tl);

    float y1 = cv::norm(tr - br);
    float y2 = cv::norm(tl - bl);

    int w = static_cast<int>(std::max(x1, x2));
    int h = static_cast<int>(std::max(y1, y2));

    std::vector<cv::Point2f> dst = {
        cv::Point2f(0, 0),
        cv::Point2f(w - 1, 0),
        cv::Point2f(w - 1, h - 1),
        cv::Point2f(0, h - 1)
    };

    // Calculate the transformation matrix
    cv::Mat M = cv::getPerspectiveTransform(corners, dst);

    // Create windows to view the video
    cv::namedWindow("Original", cv::WINDOW_NORMAL);
    cv::namedWindow("Perspective Corrected", cv::WINDOW_NORMAL);

    for (int i = 0; i < 250; ++i) {
        cv::Mat frame;
        capture >> frame;

        if (frame.empty()) {
            break;
        }

        // Annotate circles on each corner of the frame
        cv::Mat annotated_frame = frame.clone();
        cv::circle(annotated_frame, tl, 5, cv::Scalar(24, 167, 254), 2, -1);
        cv::circle(annotated_frame, tr, 5, cv::Scalar(24, 167, 254), 2, -1);
        cv::circle(annotated_frame, br, 5, cv::Scalar(24, 167, 254), 2, -1);
        cv::circle(annotated_frame, bl, 5, cv::Scalar(24, 167, 254), 2, -1);

        // Apply the perspective correction
        cv::Mat warp;
        cv::warpPerspective(frame, warp, M, cv::Size(w, h));

        // Show the original and corrected video
        cv::imshow("Original", annotated_frame);
        cv::imshow("Perspective Corrected", warp);
        cv::waitKey(30);
    }

    // Close all windows and release handles
    capture.release();
    cv::destroyAllWindows();

    return 0;
}
