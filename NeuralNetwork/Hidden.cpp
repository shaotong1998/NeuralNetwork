#include "Hidden.h"

Hidden::Hidden()
{
	
}

void Hidden::connectionByConvolution(Input input,int outputLength)//������input�ã��������Ե���������
{
	this->length = outputLength;
	Util util;
	this->w = util.getFilter();
	//��������о������,Ӧ���ȳ�ʼ��w��Ϊδ��Ҫ���µ�
	vector<vector<int>> inputImage = input.getInput();
	//����filter����Ŀ��inputImage�����ڿ�ʼ���������ͨ�����������this.image
	//����˴�СΪ5������Ϊ1��û��padding
	//28*28�Ŀ�image
	image.resize(this->length);
	for (int i = 0; i < image.size(); i++) {
		image[i].resize(this->length);
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


