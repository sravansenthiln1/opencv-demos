#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/stitching.hpp>

int main() {
    std::vector<cv::Mat> images;

    // Read and resize the first image
    cv::Mat image1 = cv::imread("./image-l.png");
    cv::resize(image1, image1, cv::Size(256, 192));
    images.push_back(image1);

    // Read and resize the second image
    cv::Mat image2 = cv::imread("./image-r.png");
    cv::resize(image2, image2, cv::Size(256, 192));
    images.push_back(image2);

    // Create an object from the Stitcher class
    cv::Ptr<cv::Stitcher> stitcher = cv::Stitcher::create();

    // Stitch the images together
    cv::Stitcher::Status status;
    cv::Mat stitched;
    status = stitcher->stitch(images, stitched);

    // Check if stitching was successful
    if (status == cv::Stitcher::Status::OK) {
        // Display the stitched image
        cv::imshow("opencv-demos", stitched);
        cv::waitKey(2000);

        // Save the stitched image output
        cv::imwrite("stitched_image.png", stitched);
    }

    // Close all windows
    cv::destroyAllWindows();

    return 0;
}
