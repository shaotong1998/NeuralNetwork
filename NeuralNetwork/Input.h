#pragma once
#include<vector>
#include<iostream>
using namespace std;
//һ����Ԫ����ʲô��
/*
* 1.��Ϊ������˵ÿ����ԪӦ����һ��ͼ
* 
*/
class Input
{
private:
	vector<vector<double>> image;
	int bias = 0;
	
public:
	Input();
	Input(vector<vector<double>> image);
	vector<vector<double>> getInput();

};

