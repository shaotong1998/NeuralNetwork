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
	vector<vector<int>> image;
	int bias = 0;
	
public:
	Input();
	Input(vector<vector<int>> image);

};

