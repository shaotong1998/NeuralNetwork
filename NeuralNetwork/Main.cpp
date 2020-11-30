//2020/11/21 15:00


#include <iostream>
#include<fstream>
#include"resource.h"
#include "LeNet5.h"
#include "DataLoader.h"
//#include<torch/torch.h>
//#include<ATen/ATen.h>
//#include<opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<vector>
#include"Util.h"
#include"LearnOpencv.h"


using namespace std;


int main()
{
    cv::Mat image;
    cout << "start" << endl;
    image = cv::imread("T:\\Cneuralnetwork\\t10k-images\\0_0.bmp");
    if (image.empty()) {
        cout << "没有分配到对象" << endl;
    }
    LearnOpencv lo(image);
    //cv::Mat gray = lo.color2gray();
    //lo.accessPixel();
    //lo.createGrayImage();
    //lo.passParameter(arr);
    //lo.printImageVector();
    //Util a;
    //vector<vector<double>> v = a.getFilter();
    //lo.image2Array();
    
    //LeNet5 lenet(lo.image2Array()); //用一个图像来生成一个lenet网络
    //lenet.initLeNet5();

    string trainImage = "T:\\Cneuralnetwork\\mnist\\train-images.idx3-ubyte";
    DataLoader d(trainImage);
    d.readTrainImage();


    

   
   

    cv::waitKey(0);
    return 0;
}

