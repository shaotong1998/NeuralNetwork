#pragma once
#include<fstream>
#include<string>
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
	void printA();
	uint32_t highEndian2LowEndian(int32_t value);
};
