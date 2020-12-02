#pragma once
#include<iostream>
#include<vector>
using namespace std;
class Util
{
public:
	Util();
	vector<vector<double>> getFilter();
	vector<vector<double>> getWeight();
	void printFilter(vector<vector<double>> v);
	double matrixInnerProduct(vector<vector<double>> a, vector<vector<double>> b);

	double sigmoid(double x);
};

/*
* �ٸ�����ʵ��һЩ�����Ĺ���
* ���������²�����
*/