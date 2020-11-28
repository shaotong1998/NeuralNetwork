#pragma once
#include<vector>
#include<iostream>
using namespace std;
//一个神经元包含什么？
/*
* 1.作为输入来说每个神经元应该是一个图
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

