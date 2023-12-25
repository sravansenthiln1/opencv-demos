#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>

int main() {
    // Read the sample image
    cv::Mat image = cv::imread("./sample.png");

    // Display the image for 2000 ms (or) 2 seconds.
    cv::imshow("opencv-demos", image);
    cv::waitKey(2000);

    // Print the shape of the image
    std::cout << "Height: " << image.rows << std::endl;
    std::cout << "Width: " << image.cols << std::endl;
    std::cout << "Color Channels: " << image.channels() << std::endl;

    // Draw a line on the image, between point (0, 0) and (255, 255),
    // with Blue in BGR color, and a line thickness of 5px
    cv::line(image, cv::Point(0, 0), cv::Point(255, 255), cv::Scalar(255, 0, 0), 5);

    cv::imshow("opencv-demos", image);
    cv::waitKey(2000);

    // Draw a rectangle on the image, provided the top left and bottom right corner
    // with White in BGR color.
    cv::rectangle(image, cv::Point(0, 0), cv::Point(127, 127), cv::Scalar(255, 255, 255), 2);

    cv::imshow("opencv-demos", image);
    cv::waitKey(2000);

    // Draw a filled rectangle on the image with Green in BGR color.
    cv::rectangle(image, cv::Point(0, 180), cv::Point(255, 255), cv::Scalar(0, 255, 0), -1);

    cv::imshow("opencv-demos", image);
    cv::waitKey(2000);

    // Write "OpenCV" on the image in white text
    cv::putText(image, "OpenCV", cv::Point(10, 200), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(255, 255, 255), 1, cv::LINE_AA);

    cv::imshow("opencv-demos", image);
    cv::waitKey(2000);

    // Save the image as an output image
    cv::imwrite("./output.png", image);

    // Close all windows
    cv::destroyAllWindows();

    return 0;
}
