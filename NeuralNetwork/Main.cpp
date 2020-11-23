//2020/11/21 15:00


#include <iostream>
#include<fstream>
#include"resource.h"
#include "LeNet5.h"
#include "DataLoader.h"

#include<opencv2/opencv.hpp>

using namespace std;


int main()
{
    cv::Mat image;
    cout << image.cols << endl;
    image = cv::imread("T:\\Cneuralnetwork\\t10k-images\\0_0.bmp");
    if (image.empty()) {
        cout << "没有分配到对象" << endl;
    }

    cout << image.cols;
   
    cv::namedWindow("niaho");
    cv::imshow("图片", image);
    cv::imshow("aaa", image);
   


    return 0;
}

