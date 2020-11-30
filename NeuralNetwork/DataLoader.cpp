#include "DataLoader.h"
#include <iostream>
#include <bitset>
#include <vector>
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
	this->mnistFile = input;  //�ļ�·��
}

void DataLoader::readTrainImage() {
	//�Զ�ģʽ���ļ�
	ifstream infile(this->mnistFile,ios::in|ios::binary);  //�����ƶ��ķ�ʽ���ļ�
	if (!infile) {
		cout << "��ȡ�ļ�ʧ��" << endl;
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

	//�Զ����Ƶķ��������int��������--���Կ��������Դ�������������
	/*
	cout << "magicNumber bin:=" << bitset<sizeof(unsigned int) * 8>(magicNumber) << endl;
	cout << "numberOfImages bin:=" << bitset<sizeof(unsigned int) * 8>(highEndian2LowEndian( numberOfImages)) << endl;
	cout << "numberOfImages bin:=" << bitset<sizeof(unsigned int) * 8>(numberOfImages) << endl;
	cout << "numberOfRows        bin:=" << bitset<sizeof(unsigned int) * 8>(numberOfRows) << endl;
	cout << "numberOfColums      bin:=" << bitset<sizeof(unsigned int) * 8>(numberOfColums) << endl;
	*/
	//��Ȼ��ѡ���ö�άvector������ͼƬ��
	vector<vector<vector<int>>> trainData(numberOfImages);
	for (int i = 0; i < numberOfRows; i++) {
		trainData[i].resize(numberOfRows);
		for (int j = 0; j < numberOfColums; j++) {
			trainData[i][j].resize(numberOfColums);
		}
	}
	//cout << trainData[0][0].size();
	//28һ��һ���Ķ��� ����һ���ֽڴ���һ�����أ�����int��4���ֽ�
	for (int n = 0; n < 100; n++) {
		for (int i = 0; i < numberOfRows; i++) {
			for (int j = 0; j < numberOfRows; j++) {
				//trainData[n][i][j] = infile.get();
				//cout << infile.get();
			}
			//cout << endl;
		}
		//cout << endl;
	}
	

	
}