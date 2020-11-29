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
	vector<vector<double>> w; //在卷积中为kernal，这是需要学习的。需要初始化一个kernal
	int length = 0;//当前隐层的图形长度
	
public:
	Hidden();
	
	void connectionByConvolution(Input input,int outputLength);

};

