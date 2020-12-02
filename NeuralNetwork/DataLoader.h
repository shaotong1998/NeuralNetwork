#pragma once
#include<fstream>
#include<string>
#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

class DataLoader
{
private:
	int temp = 666;
	string mnistFile;
	//string fileLocal;
public:
	DataLoader(string input);
	void readTrainImage();
	vector<vector<vector<double>>> readTrainImage(int num,int length);
	void printA();
	uint32_t highEndian2LowEndian(int32_t value);
};
