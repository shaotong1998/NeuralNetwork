#pragma once
#include<iostream>
#include<vector>
using namespace std;
class Util
{
public:
	Util();
	vector<vector<double>> getFilter();
	void printFilter(vector<vector<double>> v);
	double matrixInnerProduct(vector<vector<double>> a, vector<vector<double>> b);
};

/*
* �ٸ�����ʵ��һЩ�����Ĺ���
* ���������²�����
*/