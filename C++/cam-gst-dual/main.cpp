#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

int main(int argc, char* argv[]) {
    // Get the video device node
    std::string camera_arg_1 = argv[1];
    std::string camera_arg_2 = argv[2];

    // Capture Parameters
    std::string width = "3840";
    std::string height = "2160";
    std::string fps = "30";
    std::string camera_format = "NV12";

    std::string gst_1 = "v4l2src device=" + camera_arg + " ! video/x-raw,format=" + camera_format + 
                        ",width=" + width +",height=" + height + ",framerate=" + fps + "/1 ! videoconvert ! appsink";
    std::string gst_2 = "v4l2src device=" + camera_arg + " ! video/x-raw,format=" + camera_format + 
                        ",width=" + width +",height=" + height + ",framerate=" + fps + "/1 ! videoconvert ! appsink";
    
    // Select GStreamer for video capture
    cv::VideoCapture capture_1(gst_1, cv::CAP_GSTREAMER);
    cv::VideoCapture capture_2(gst_2, cv::CAP_GSTREAMER);

    // Check if the video capture is successful
    if (!capture_1.isOpened()) {
        std::cout << "Error opening video 1 capture." << std::endl;
        return 1;
    }

    if (!capture_2.isOpened()) {
        std::cout << "Error opening video 2 capture." << std::endl;
        return 1;
    }

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
