#include "LeNet5.h"

LeNet5::LeNet5()
{
}

LeNet5::LeNet5(vector<vector<int>> image)
{
    this->image = image;
}

int LeNet5::initLeNet5()
{
    //��һ����5*5��6�������
    //ͨ���������������input��������hidden
    //����
    Input inputNeural(this->image);
    //1.C1�㣬��������28*28��
    vector<Hidden> C1(6);//ÿһ��������filter���о������
    //for (int i = 0; i < C1.size(); i++) {

    //}
    C1[0].connectionByConvolution(inputNeural, 28);

    return 0;
}
