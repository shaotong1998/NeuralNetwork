#pragma once

#include<iostream>
#include<vector>
#include"Input.h"
#include"Util.h"
using namespace std;


class Hidden
{
private:
	vector<vector<double>> image; //ͨ����������²����õ���ͼ��
	vector<vector<double>> w;     //�ھ����Ϊkernal��������Ҫѧϰ�ġ���Ҫ��ʼ��һ��kernal
	double bias;                  //ƫ�ã������ʼ��
	int imageLength = 0;
	
public:
	Hidden();
	int getLength();
	vector<vector<double>> getImage();

	//���
	void connectionByConvolution(Input input,int outputLength);

	//�²���
	void max_subSamping(Hidden input,int length);
	double maxPixel(double a, double b, double c, double d);

	//���ܷ���
	void printImage();
	double sigmoid(double x);

};

