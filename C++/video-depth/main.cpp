#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/calib3d/calib3d.hpp>

int main() {
    // Set the sample video as the input source
    cv::VideoCapture capture_l("./stereo_l.mp4");
    cv::VideoCapture capture_r("./stereo_r.mp4");

    // Create windows to view the video
    cv::namedWindow("opencv-demos", cv::WINDOW_NORMAL);
    cv::namedWindow("left", cv::WINDOW_NORMAL);
    cv::namedWindow("right", cv::WINDOW_NORMAL);

    // Create an object from the StereoSGBM Class
    cv::Ptr<cv::StereoSGBM> stereo = cv::StereoSGBM::create(0, 16, 3);

    // Preview the original video
    for (int i = 0; i < 200; ++i) {
        cv::Mat frame_l, frame_r;
        capture_l >> frame_l;
        capture_r >> frame_r;

        if (frame_l.empty() || frame_r.empty()) {
            break;
        }

        cv::resize(frame_l, frame_l, cv::Size(256, 192));
        cv::resize(frame_r, frame_r, cv::Size(256, 192));

        cv::cvtColor(frame_l, frame_l, cv::COLOR_BGR2GRAY);
        cv::cvtColor(frame_r, frame_r, cv::COLOR_BGR2GRAY);

        cv::Mat disparity;
        stereo->compute(frame_l, frame_r, disparity);

        if (disparity.empty()) {
            continue;
        }

        // Normalize the depth map
        cv::Mat normalized_disparity;
        cv::normalize(disparity, normalized_disparity, 0, 255, cv::NORM_MINMAX);

        // Convert to 8-bit single-channel
        normalized_disparity.convertTo(normalized_disparity, CV_8U);

        // Map the depth to a colormap
        cv::Mat disparity_colormap;
        cv::applyColorMap(normalized_disparity, disparity_colormap, cv::COLORMAP_VIRIDIS);

        cv::imshow("left", frame_l);
        cv::imshow("right", frame_r);
        cv::imshow("opencv-demos", disparity_colormap);
        cv::waitKey(30);
    }

    // Close windows and release handles
    capture_l.release();
    capture_r.release();
    cv::destroyAllWindows();

    return 0;
}
