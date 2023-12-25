#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

int main(int argc, char* argv[]) {
    // Get the video device node
    std::string camera_arg_1 = argv[1];
    std::string camera_arg_2 = argv[2];

    // Capture Parameters
    int width = 3840;
    int height = 2160;
    int fourcc = cv::VideoWriter::fourcc('U', 'Y', 'V', 'Y');

    // Select v4l2 for video capture
    cv::VideoCapture capture_1(std::stoi(camera_arg_1.substr(10)), cv::CAP_V4L2);
    cv::VideoCapture capture_2(std::stoi(camera_arg_2.substr(10)), cv::CAP_V4L2);

    // Check if the video capture is successful
    if (!capture_1.isOpened()) {
        std::cout << "Error opening video 1 capture." << std::endl;
        return 1;
    }

    if (!capture_2.isOpened()) {
        std::cout << "Error opening video 2 capture." << std::endl;
        return 1;
    }

    // Configure video format and resolution
    capture_1.set(cv::CAP_PROP_FOURCC, fourcc);
    capture_1.set(cv::CAP_PROP_FRAME_WIDTH, width);
    capture_1.set(cv::CAP_PROP_FRAME_HEIGHT, height);

    capture_2.set(cv::CAP_PROP_FOURCC, fourcc);
    capture_2.set(cv::CAP_PROP_FRAME_WIDTH, width);
    capture_2.set(cv::CAP_PROP_FRAME_HEIGHT, height);

    // Create a window to view the video
    cv::namedWindow("video 1", cv::WINDOW_NORMAL);
    cv::namedWindow("video 2", cv::WINDOW_NORMAL);

    // Preview 100 video frames at ~30 frames per second
    for (int i = 0; i < 100; ++i) {
        cv::Mat frame_1, frame_2;
        capture_1 >> frame_1;
        capture_2 >> frame_2;

        if (frame_1.empty() || frame_2.empty()) {
            break;
        }

        cv::imshow("video 1", frame);
        cv::imshow("video 2", frame);
        cv::waitKey(30);
    }

    // Release the video capture
    capture_1.release();
    capture_2.release();
    cv::destroyAllWindows();

    return 0;
}
