#include "Hidden.h"

Hidden::Hidden()
{
	
}

int Hidden::getLength()
{
	return this->imageLength;
}

vector<vector<double>> Hidden::getImage()
{
	//vector<vector<double>> res = this->image;
	return this->image;
}

void Hidden::connectionByConvolution(Input input,int outputLength)//������input�ã��������Ե���������
{
	this->imageLength = outputLength;
	Util util;
	this->w = util.getFilter();
	//��������о������,Ӧ���ȳ�ʼ��w��Ϊδ��Ҫ���µ�
	vector<vector<int>> inputImage = input.getInput();
	//����filter����Ŀ��inputImage�����ڿ�ʼ���������ͨ�����������this.image
	//����˴�СΪ5������Ϊ1��û��padding
	//28*28�Ŀ�image
	image.resize(this->imageLength);
	for (int i = 0; i < image.size(); i++) {
		image[i].resize(this->imageLength);
	}
	//5*5�Ŀո���Ұ
	vector<vector<double>> scaner(w.size());
	for (int i = 0; i < w.size(); i++) {
		scaner[i].resize(w.size());
	}
	;
	for (int i = 0; i < image.size(); i++) {//��ѭ��28*28��
		for (int j = 0; j < image[i].size(); j++) {
			//���
			//��Ҫ����inputImage��ȡ��5*5�ľ��󣬲������͵�util�еľ��������ȥ
	
			for (int k = i; k < i + 5; k++) {
				for (int l = j; l < j + 5; l++) {
					//debug:scaner��Խ�磡
					scaner[k - i][l - j] = inputImage[k][l];
				}
			}
			//util.printFilter(scaner);
			image[i][j] = util.matrixInnerProduct(scaner,this->w);
		}
	}
	//util.printFilter(image); //�õ�һ��28*28��ͼ��
	
}

void Hidden::max_subSamping(Hidden input,int length)
{
	//lengthΪ�²����Ĵ��ڴ�С��lenet5Ϊ2
	this->imageLength = input.imageLength /length;  
	vector<vector<double>> inputImage = input.getImage();

	vector<vector<double>> max_subImage(this->imageLength);  //s2��14*14
	for (int i = 0; i < max_subImage.size(); i++) {
		max_subImage[i].resize(imageLength);
	}
	
	for (int i = 0; i < input.getLength(); i = i + 2) {
		for (int j = 0; j < input.getLength(); j = j + 2) {
			max_subImage[i / 2][j / 2] = maxPixel(inputImage[i][j],inputImage[i][j+1],inputImage[i+1][j],inputImage[i+1][j+1]);
		}
	}
	this->image = max_subImage;
}

double Hidden::maxPixel(double a, double b, double c, double d)
{
	//double tem;
	if (a >= b) {//a b �������ֵ
		b = a;
	}
	else {
		a = b;
	}
	if (c >= d) {
		d = c;
	}
	else {
		c = d;
	}
	if (a > c) {
		return a;
	}
	else {
		return c;
	}
}

void Hidden::printImage()
{
	Util util;
	util.printFilter(this->image);
}


