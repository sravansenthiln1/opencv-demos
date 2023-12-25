#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

int main() {
    // Create various image processing kernels
    cv::Mat sharpen_kernel = (cv::Mat_<float>(3, 3) << 0, -1, 0, 
                                                      -1, 5, -1, 
                                                       0, -1, 0);

    cv::Mat edge_kernel = (cv::Mat_<float>(3, 3) << -1, -1, -1, 
                                                    -1, 8, -1, 
                                                    -1, -1, -1);

    cv::Mat blur_kernel = (1.0 / 25) * (cv::Mat_<float>(5, 5) << 1, 1, 1, 1, 1,
                                                                 1, 1, 1, 1, 1,
                                                                 1, 1, 1, 1, 1,
                                                                 1, 1, 1, 1, 1,
                                                                 1, 1, 1, 1, 1);

    cv::Mat vblur_kernel = (1.0 / 5) * (cv::Mat_<float>(5, 5) << 0, 0, 1, 0, 0,
                                                                0, 0, 1, 0, 0,
                                                                0, 0, 1, 0, 0,
                                                                0, 0, 1, 0, 0,
                                                                0, 0, 1, 0, 0);

    cv::Mat hblur_kernel = (1.0 / 5) * (cv::Mat_<float>(5, 5) << 0, 0, 0, 0, 0,
                                                                 0, 0, 0, 0, 0,
                                                                 1, 1, 1, 1, 1,
                                                                 0, 0, 0, 0, 0,
                                                                 0, 0, 0, 0, 0);

    // Read the sample image
    cv::Mat image = cv::imread("./sample.png");

    // Display the image for 2000 ms (or) 2 seconds.
    cv::imshow("opencv-demos", image);
    cv::waitKey(2000);

    // Color examples

    // Grayscale conversion of Image
    cv::Mat grayscale;
    cv::cvtColor(image, grayscale, cv::COLOR_BGR2GRAY);
    cv::imshow("opencv-demos", grayscale);
    cv::waitKey(2000);

    // Image color channel extraction
    cv::Mat green_channel = image.clone();
    green_channel.col(0).setTo(0);
    green_channel.col(2).setTo(0);
    cv::imshow("opencv-demos", green_channel);
    cv::waitKey(2000);

    // Filter examples

    // Image sharpening
    cv::Mat sharpened_image;
    cv::filter2D(image, sharpened_image, -1, sharpen_kernel);
    cv::imshow("opencv-demos", sharpened_image);
    cv::waitKey(2000);

    // Image edge detection
    cv::Mat edge_image;
    cv::filter2D(image, edge_image, -1, edge_kernel);
    cv::imshow("opencv-demos", edge_image);
    cv::waitKey(2000);

    // Image blurring
    cv::Mat blurred_image;
    cv::filter2D(image, blurred_image, -1, blur_kernel);
    cv::imshow("opencv-demos", blurred_image);
    cv::waitKey(2000);

    // Image vertical motion blur
    cv::Mat vblurred_image;
    cv::filter2D(image, vblurred_image, -1, vblur_kernel);
    cv::imshow("opencv-demos", vblurred_image);
    cv::waitKey(2000);

    // Image horizontal motion blur
    cv::Mat hblurred_image;
    cv::filter2D(image, hblurred_image, -1, hblur_kernel);
    cv::imshow("opencv-demos", hblurred_image);
    cv::waitKey(2000);

    // Close all windows
    cv::destroyAllWindows();

    return 0;
}
