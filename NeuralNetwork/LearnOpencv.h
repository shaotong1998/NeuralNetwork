#pragma once
//#include<opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<iostream>
#include<vector>
using namespace std;
class LearnOpencv
{
private:
	cv::Mat image;
	cv::Mat grayImage;
	int row = 0;
	int col = 0;
	//vector<vector<int>> a;
public:
	LearnOpencv(cv::Mat image);
	//cv::Mat color2gray();
	//把图像转化成灰度图
	cv::Mat color2gray();
	//显示图像
	void showImage(cv::Mat image);
	//访问像素
	void accessPixel();
	//创造一个图像
	void createImage();
	void createGrayImage();
	//把一个mat类型的图像转换为一个二维的arr
	vector<vector<int>> image2Array();
	//打印vector
	void printImageVector();
	//测试最大值
	double maxPixel(double a, double b, double c, double d);
};

