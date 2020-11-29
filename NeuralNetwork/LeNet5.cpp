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
    //第一层有5*5的6个卷积核
    //通过卷积操作，利用input生成六个hidden
    //输入
    Input inputNeural(this->image);
    //1.C1层，包含六个28*28神经
    vector<Hidden> C1(6);//每一个对象与filter进行卷积操作
    //for (int i = 0; i < C1.size(); i++) {

    //}
    C1[0].connectionByConvolution(inputNeural, 28);

    return 0;
}
