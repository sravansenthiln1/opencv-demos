#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

int main() {
    // Read the sample image
    cv::Mat image = cv::imread("./sample.png");

    // Preview the image
    cv::imshow("opencv-demos", image);
    cv::waitKey(2000);

    // Create the arrays of points of the warped object
    cv::Point2f tl(116, 92);
    cv::Point2f tr(308, 144);
    cv::Point2f br(236, 416);
    cv::Point2f bl(42, 364);

    // Annotate circles on each corner of the image
    cv::Mat annotated_image = image.clone();
    cv::circle(annotated_image, tl, 5, cv::Scalar(24, 167, 254), 2, -1);
    cv::circle(annotated_image, tr, 5, cv::Scalar(24, 167, 254), 2, -1);
    cv::circle(annotated_image, br, 5, cv::Scalar(24, 167, 254), 2, -1);
    cv::circle(annotated_image, bl, 5, cv::Scalar(24, 167, 254), 2, -1);

    // Preview the image with the corner points
    cv::imshow("opencv-demos", annotated_image);
    cv::waitKey(2000);

    // Define the corners array
    cv::Point2f corners[4] = {tl, tr, br, bl};

    float x1 = cv::norm(br - bl);
    float x2 = cv::norm(tr - tl);

    float y1 = cv::norm(tr - br);
    float y2 = cv::norm(tl - bl);

    int w = static_cast<int>(std::max(x1, x2));
    int h = static_cast<int>(std::max(y1, y2));

    // Define the destination points
    cv::Point2f dst[4] = {
        cv::Point2f(0, 0),
        cv::Point2f(w - 1, 0),
        cv::Point2f(w - 1, h - 1),
        cv::Point2f(0, h - 1)
    };

    // Calculate the transformation matrix
    cv::Mat M = cv::getPerspectiveTransform(corners, dst);

    // Transform the image
    cv::Mat warp;
    cv::warpPerspective(image, warp, M, cv::Size(w, h));

    // Show the image from the correct perspective
    cv::imshow("opencv-demos", warp);
    cv::waitKey(2000);

    // Save the image as an output image
    cv::imwrite("./output.png", image);

    // Close all windows
    cv::destroyAllWindows();

    return 0;
}
