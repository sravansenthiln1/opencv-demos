#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/calib3d/calib3d.hpp>

int main() {
    // Append the sample images
    cv::Mat image_l = cv::imread("./stereo_l.png", cv::IMREAD_GRAYSCALE);
    cv::Mat image_r = cv::imread("./stereo_r.png", cv::IMREAD_GRAYSCALE);

    // Create an object from the StereoSGBM Class
    cv::Ptr<cv::StereoSGBM> stereo = cv::StereoSGBM::create(0, 16, 3);

    // Calculate the disparity map
    cv::Mat disparity;
    stereo->compute(image_l, image_r, disparity);

    // Normalize the disparity map
    cv::Mat normalized_disparity;
    cv::normalize(disparity, normalized_disparity, 0, 255, cv::NORM_MINMAX);

    // Convert to 8-bit single-channel
    normalized_disparity.convertTo(normalized_disparity, CV_8U);

    // Map the disparity to a colormap
    cv::Mat disparity_colormap;
    cv::applyColorMap(normalized_disparity, disparity_colormap, cv::COLORMAP_VIRIDIS);

    // Display the stitched image
    cv::imshow("opencv-demos", disparity_colormap);
    cv::waitKey(5000);

    // Close all windows
    cv::destroyAllWindows();

    return 0;
}
