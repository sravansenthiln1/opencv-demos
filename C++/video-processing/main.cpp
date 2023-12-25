#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int main() {
    // Create various image processing kernels
    cv::Mat sharpen_kernel = (cv::Mat_<float>(3, 3) << 0, -1, 0, 
                                                      -1, 5, -1, 
                                                       0, -1, 0);

    cv::Mat edge_kernel = (cv::Mat_<float>(3, 3) << -1, -1, -1, 
                                                    -1, 8, -1, 
                                                    -1, -1, -1);
    // Set the sample video as the input source
    cv::VideoCapture capture("./video.mp4");

    // Check if the video capture is successful
    if (!capture.isOpened()) {
        std::cout << "Error opening video capture." << std::endl;
        return 1;
    }

    // Create a window to view the video
    cv::namedWindow("opencv-demos", cv::WINDOW_NORMAL);

    // Preview the original video
    for (int i = 0; i < 500; ++i) {
        cv::Mat frame;
        capture >> frame;

        if (frame.empty()) {
            break;
        }

        cv::imshow("opencv-demos", frame);
        cv::waitKey(30);
    }

    // View the video with a sharpening kernel applied
    for (int i = 0; i < 100; ++i) {
        cv::Mat frame;
        capture >> frame;

        if (frame.empty()) {
            break;
        }

        cv::Mat sharpened_image;
        cv::filter2D(frame, sharpened_image, -1, sharpen_kernel);

        cv::imshow("opencv-demos", sharpened_image);
        cv::waitKey(30);
    }

    // View the video with an edge detection kernel applied
    for (int i = 0; i < 100; ++i) {
        cv::Mat frame;
        capture >> frame;

        if (frame.empty()) {
            break;
        }

        cv::Mat edge_image;
        cv::filter2D(frame, edge_image, -1, edge_kernel);

        cv::imshow("opencv-demos", edge_image);
        cv::waitKey(30);
    }

    // Close all windows and release handles
    capture.release();
    cv::destroyAllWindows();

    return 0;
}
