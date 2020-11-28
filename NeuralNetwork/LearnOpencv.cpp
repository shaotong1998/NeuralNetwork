#include "LearnOpencv.h"

LearnOpencv::LearnOpencv(cv::Mat image) {
	this->image = image;
	this->col = image.cols;
	this->row = image.rows;
}

cv::Mat LearnOpencv::color2gray() {
	cv::Mat grayImage;
	//cout << "��ǰͼ���channelΪ��" << image.channels() << endl;
	cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);
	//�����ͼƬ�Ŵ�32*32
	cv::resize(grayImage, grayImage, cv::Size(32, 32));
	this->grayImage = grayImage;//ע�⣡����ǳ����
	

	return grayImage;
}

void LearnOpencv::showImage(cv::Mat image) {
	cv::imshow("image",image);
}

void LearnOpencv::accessPixel() {
	color2gray();
	cout << "�Ҷ�ͼ��ͨ����Ϊ��" << this->grayImage.channels()<<endl;
	for (int i = 0; i < 28; i++) {
		for (int j = 0; j < 28; j++) {
			cout << (this->grayImage.at<unsigned char>(i, j))-'0' + 48 << " ";
		}
		cout << endl;
	}
	//cout << this->grayImage.at<char>(1, 1);
}

void LearnOpencv::createImage()
{
	cv::Mat image(288, 288, CV_8UC3,cv::Scalar(0,0,255));
	showImage(image);

}

void LearnOpencv::createGrayImage()
{
	cv::Mat image(288, 288,CV_8U,cv::Scalar(65));
	/*for (int i = 0; i < 28; i++) {
		for (int j = 0; j < 28; j++) {
			cout <<image.at<unsigned char>(i, j) << " ";
		}
		cout << endl;
	}
	showImage(image);*/
	
}

vector<vector<int>> LearnOpencv::image2Array()
{
	cv::Mat targetImage = color2gray();//��Ŀ��ͼ��ת��Ϊ�Ҷ�ͼȻ����
	cv::imshow("32", targetImage);
	vector<vector<int>> varr(this->row);  //�����άvevtor Row��
	for (int i = 0; i < varr.size(); i++) {
		varr[i].resize(this->col);       // ÿ������Ϊ��
	}
	for (int i = 0; i < varr.size(); i++) {
		for (int j = 0; j < varr[i].size(); j++) {
			varr[i][j] = (targetImage.at<unsigned char>(i, j)) - '0' + 48;
		}
	}
	return varr;
}

void LearnOpencv::printImageVector()
{
	vector<vector<int>> v = image2Array();
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}












//��c++Ҳ̫���ˣ�����ԶҲѧ������c++ 2020/11/25 16��23