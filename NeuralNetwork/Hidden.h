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
	vector<vector<double>> w; //�ھ����Ϊkernal��������Ҫѧϰ�ġ���Ҫ��ʼ��һ��kernal
	int length = 0;//��ǰ�����ͼ�γ���
	
public:
	Hidden();
	
	void connectionByConvolution(Input input,int outputLength);

};

