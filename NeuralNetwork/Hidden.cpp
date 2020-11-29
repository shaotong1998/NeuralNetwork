#include "Hidden.h"

Hidden::Hidden()
{
	
}

void Hidden::connectionByConvolution(Input input,int outputLength)//还是用input好，这样就显得连起来了
{
	this->length = outputLength;
	Util util;
	this->w = util.getFilter();
	//在这里进行卷积操作,应当先初始化w作为未来要更新的
	vector<vector<int>> inputImage = input.getInput();
	//有了filter有了目标inputImage，终于开始卷积操作。通过卷积来更新this.image
	//卷积核大小为5，步长为1，没有padding
	//28*28的空image
	image.resize(this->length);
	for (int i = 0; i < image.size(); i++) {
		image[i].resize(this->length);
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


