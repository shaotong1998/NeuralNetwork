#include "DataLoader.h"
using namespace std;

void DataLoader::printA() {
	cout << "hhhhhh";
}

uint32_t DataLoader::highEndian2LowEndian(int32_t value)
{
	return ((value & 0x000000FF)<<24) |
		((value & 0x0000FF00)<<8)|
		((value & 0x00FF0000)>>8)|
		((value & 0xFF000000)>>24);
}

DataLoader::DataLoader(string input)
{
	this->mnistFile = input;  //文件路径
}

void DataLoader::readTrainImage() {
	//以读模式打开文件
	ifstream infile(this->mnistFile,ios::in|ios::binary);  //二进制读的方式打开文件
	if (!infile) {
		cout << "读取文件失败" << endl;
	}
	uint32_t magicNumber;
	uint32_t numberOfImages;
	uint32_t numberOfRows;
	uint32_t numberOfColums;
	//infile.seekg(0, infile.beg);
	infile.read((char*)&magicNumber, 4);
	infile.read((char*)&numberOfImages, 4);
	infile.read((char*)&numberOfRows, 4);
	infile.read((char*)&numberOfColums, 4);
	
	numberOfImages = highEndian2LowEndian(numberOfImages);
	numberOfRows = highEndian2LowEndian(numberOfRows);
	numberOfColums = highEndian2LowEndian(numberOfColums);

	//以二进制的方法来输出int类型数据--可以看出这是以大端序来输出数据
	/*
	cout << "magicNumber bin:=" << bitset<sizeof(unsigned int) * 8>(magicNumber) << endl;
	cout << "numberOfImages bin:=" << bitset<sizeof(unsigned int) * 8>(highEndian2LowEndian( numberOfImages)) << endl;
	cout << "numberOfImages bin:=" << bitset<sizeof(unsigned int) * 8>(numberOfImages) << endl;
	cout << "numberOfRows        bin:=" << bitset<sizeof(unsigned int) * 8>(numberOfRows) << endl;
	cout << "numberOfColums      bin:=" << bitset<sizeof(unsigned int) * 8>(numberOfColums) << endl;
	*/
	//当然是选择用二维vector来保存图片了
	vector<vector<vector<int>>> trainData(numberOfImages);
	for (int i = 0; i < numberOfImages; i++) {
		trainData[i].resize(numberOfRows);
		for (int j = 0; j < numberOfColums; j++) {
			trainData[i][j].resize(numberOfColums);
		}
	}
	//cout << trainData[0][0].size();
	//28一批一批的读入 但是一个字节代表一个像素，但是int是4个字节
	for (int n = 0; n < 100; n++) {
		for (int i = 0; i < numberOfRows; i++) {
			for (int j = 0; j < numberOfRows; j++) {
				//trainData[n][i][j] = infile.get();
				cout << infile.get();
			}
			cout << endl;
		}
		cout << endl;
	}
	

	
}

vector<vector<vector<double>>> DataLoader::readTrainImage(int num,int length)
{//读取的个数，每个图片的长度
	//以读模式打开文件
	ifstream infile(this->mnistFile, ios::in | ios::binary);  //二进制读的方式打开文件
	if (!infile) {
		cout << "读取文件失败" << endl;
	}
	uint32_t magicNumber;
	uint32_t numberOfImages;
	uint32_t numberOfRows;
	uint32_t numberOfColums;
	infile.read((char*)&magicNumber, 4);
	infile.read((char*)&numberOfImages, 4);
	infile.read((char*)&numberOfRows, 4);
	infile.read((char*)&numberOfColums, 4);

	numberOfImages = highEndian2LowEndian(numberOfImages);
	numberOfRows = highEndian2LowEndian(numberOfRows);
	numberOfColums = highEndian2LowEndian(numberOfColums);

	vector<vector<vector<double>>> trainData(num);
	for (int i = 0; i < num; i++) {
		trainData[i].resize(length);
		for (int j = 0; j < length; j++) {
			trainData[i][j].resize(length);
		}
	}
	for (int n = 0; n < num; n++) {
		for (int i = 0; i < numberOfRows; i++) {
			for (int j = 0; j < numberOfRows; j++) {
				trainData[n][i][j] = infile.get();
				//cout << trainData[n][i][j];
			}
			//cout << endl;
		}
		//cout << endl;
	}
	return trainData;
}
