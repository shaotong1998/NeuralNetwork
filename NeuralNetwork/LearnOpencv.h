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
	//��ͼ��ת���ɻҶ�ͼ
	cv::Mat color2gray();
	//��ʾͼ��
	void showImage(cv::Mat image);
	//��������
	void accessPixel();
	//����һ��ͼ��
	void createImage();
	void createGrayImage();
	//��һ��mat���͵�ͼ��ת��Ϊһ����ά��arr
	vector<vector<int>> image2Array();
	//��ӡvector
	void printImageVector();
	//�������ֵ
	double maxPixel(double a, double b, double c, double d);
};

