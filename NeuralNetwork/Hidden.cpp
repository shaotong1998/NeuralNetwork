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

void Hidden::connectionByConvolution(Input input,int outputLength)//还是用input好，这样就显得连起来了
{
	this->imageLength = outputLength;
	Util util;
	this->w = util.getFilter();
	//在这里进行卷积操作,应当先初始化w作为未来要更新的
	vector<vector<int>> inputImage = input.getInput();
	//有了filter有了目标inputImage，终于开始卷积操作。通过卷积来更新this.image
	//卷积核大小为5，步长为1，没有padding
	//28*28的空image
	image.resize(this->imageLength);
	for (int i = 0; i < image.size(); i++) {
		image[i].resize(this->imageLength);
	}
	//5*5的空感受野
	vector<vector<double>> scaner(w.size());
	for (int i = 0; i < w.size(); i++) {
		scaner[i].resize(w.size());
	}
	;
	for (int i = 0; i < image.size(); i++) {//共循环28*28次
		for (int j = 0; j < image[i].size(); j++) {
			//卷积
			//主要是在inputImage中取出5*5的矩阵，并把他送到util中的矩阵相乘中去
	
			for (int k = i; k < i + 5; k++) {
				for (int l = j; l < j + 5; l++) {
					//debug:scaner会越界！
					scaner[k - i][l - j] = inputImage[k][l];
				}
			}
			//util.printFilter(scaner);
			image[i][j] = util.matrixInnerProduct(scaner,this->w);
		}
	}
	//util.printFilter(image); //得到一个28*28的图像
	
}

void Hidden::max_subSamping(Hidden input,int length)
{
	//length为下采样的窗口大小，lenet5为2
	this->imageLength = input.imageLength /length;  
	vector<vector<double>> inputImage = input.getImage();

	vector<vector<double>> max_subImage(this->imageLength);  //s2中14*14
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
	if (a >= b) {//a b 都是最大值
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


