#pragma once

#include<iostream>
#include<vector>
#include"Input.h"
#include"Util.h"
using namespace std;


class Hidden
{
private:
	vector<vector<double>> image; //通过卷积或者下采样得到的图像
	vector<vector<double>> w;     //在卷积中为kernal，这是需要学习的。需要初始化一个kernal
	double bias;                  //偏置，随机初始化
	int imageLength = 0;
	
public:
	Hidden();
	int getLength();
	vector<vector<double>> getImage();

	//卷积
	void connectionByConvolution(Input input,int outputLength);

	//下采样
	void max_subSamping(Hidden input,int length);
	double maxPixel(double a, double b, double c, double d);

	//功能方法
	void printImage();
	double sigmoid(double x);

};

