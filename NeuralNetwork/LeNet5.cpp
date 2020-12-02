#include "LeNet5.h"

LeNet5::LeNet5()
{
}

LeNet5::LeNet5(vector<vector<double>> image)
{
    this->image = image;
}

int LeNet5::initLeNet5()
{
    //��һ����5*5��6�������
    //����
    Input inputNeural(this->image);
    //1.C1�㣬��������28*28��
    vector<Hidden> C1(6);//ÿһ��������filter���о������
    for (int i = 0; i < C1.size(); i++) {
        C1[i].connectionByConvolution(inputNeural, 28);
        C1[i].printImage();
        cout << endl;
    }
    //2.S2�㣬ÿ����Ĵ�СΪ2*2�����������õ�6��14*14
    vector<Hidden> S2(6);
    for (int i = 0; i < S2.size(); i++) {
        S2[i].max_subSamping(C1[i], 2);
        S2[i].printImage();
        cout << endl;
    }
    //3.C3����㣬��Ҫ������14*14 -> 16��10*10
    //���⣺ƫ����ô�ӣ�һ����Ԫ�����м�������ˣ�
    vector<Hidden> C3(16);
    for (int i = 0; i < C3.size(); i++) {

    }

    return 0;
}
