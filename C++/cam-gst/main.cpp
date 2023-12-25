#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

int main(int argc, char* argv[]) {
    // Get the video device node
    std::string camera_arg = argv[1];

    // Capture Parameters
    std::string width = "3840";
    std::string height = "2160";
    std::string fps = "30";
    std::string camera_format = "NV12";

    std::string gst = "v4l2src device=" + camera_arg + " ! video/x-raw,format=" + camera_format + 
                      ",width=" + width +",height=" + height + ",framerate=" + fps + "/1 ! videoconvert ! appsink";

    // Select GStreamer for video capture
    cv::VideoCapture capture(gst, cv::CAP_GSTREAMER);

    // Check if the video capture is successful
    if (!capture.isOpened()) {
        std::cout << "Error opening video capture." << std::endl;
        return 1;
    }

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
