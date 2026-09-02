#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
    
    cv::Mat image = cv::imread("..\\assets\\ijasah.jpg");

    if(image.empty()){
        std::cout << "tidak dapat membaca gambar karena gambar kosong" << std::endl;
        return -1;
    }

    cv::namedWindow("Gambar", cv::WINDOW_NORMAL);
    cv::resizeWindow("Gambar", 800, 600);

    cv::Mat grayImage;
    cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);
    cv::Mat grussianBlurimage;
    cv::GaussianBlur(grayImage, grussianBlurimage, cv::Size(5,5), 0);
    cv::Mat cannyImage;
    cv::Canny(grussianBlurimage, cannyImage, 30, 100);
    // Buat kernel ukuran 3x3
cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));

// Lakukan penebalan pada hasil Canny untuk menyambung garis putus
cv::Mat gambarDilasi;
cv::dilate(cannyImage, gambarDilasi, kernel);
    
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;
    cv::findContours(cannyImage, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    cv::imshow("Gambar", gambarDilasi);
    cv::waitKey(0);

    return 0;
}