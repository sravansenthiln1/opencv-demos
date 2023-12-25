#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

int main(int argc, char* argv[]) {
    // Get the video device node
    std::string camera_arg = argv[1];

    // Capture Parameters
    int width = 3840;
    int height = 2160;
    int fourcc = cv::VideoWriter::fourcc('U', 'Y', 'V', 'Y');

    // Select v4l2 for video capture
    cv::VideoCapture capture(std::stoi(camera_arg.substr(10)), cv::CAP_V4L2);

    // Check if the video capture is successful
    if (!capture.isOpened()) {
        std::cout << "Error opening video capture." << std::endl;
        return 1;
    }

    // Configure video format and resolution
    capture.set(cv::CAP_PROP_FOURCC, fourcc);
    capture.set(cv::CAP_PROP_FRAME_WIDTH, width);
    capture.set(cv::CAP_PROP_FRAME_HEIGHT, height);

    // Create a window to view the video
    cv::namedWindow("video", cv::WINDOW_NORMAL);

    // Preview 100 video frames at ~30 frames per second
    for (int i = 0; i < 100; ++i) {
        cv::Mat frame;
        capture >> frame;

        if (frame.empty()) {
            break;
        }

        cv::imshow("video", frame);
        cv::waitKey(30);
    }

    // Release the video capture
    capture.release();
    cv::destroyAllWindows();

    return 0;
}
