#include <QCoreApplication>
#include <opencv.hpp>
#include <iostream>

using namespace std;

void salt(cv::Mat image, int n)
{
    for (int k = 0; k < n; k++)
    {
        int i = rand()%image.cols;
        int j = rand()%image.rows;

        if(image.channels() == 1) // 灰度图
        {
            image.at<uchar>(j, i) = 255;
        }
        else if(image.channels() == 3) // rgb 图
        {
            image.at<cv::Vec3b>(j, i)[0] = 255;
            image.at<cv::Vec3b>(j, i)[1] = 255;
            image.at<cv::Vec3b>(j, i)[2] = 255;
        }
    }
}

int main()
{
    cv::Mat image = cv::imread("E:\\system dir\\Desktop\\1_5.jpg");
    salt(image, 3000);
    cv::namedWindow("Image", 1);
    cv::imshow("Image", image);
    cv::waitKey(0);
    return 0;
}
