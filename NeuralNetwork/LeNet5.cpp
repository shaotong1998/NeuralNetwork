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
    //输入
    Input inputNeural(this->image);
    //1.C1层，包含六个28*28神经
    vector<Hidden> C1(6);//每一个对象与filter进行卷积操作
    for (int i = 0; i < C1.size(); i++) {
        C1[i].connectionByConvolution(inputNeural, 28);
        C1[i].printImage();
        cout << endl;
    }
    //2.S2层，每个块的大小为2*2，最大采样，得到6张14*14
    vector<Hidden> S2(6);
    for (int i = 0; i < S2.size(); i++) {
        S2[i].max_subSamping(C1[i], 2);
        S2[i].printImage();
        cout << endl;
    }
    //3.C3卷积层，需要把六张14*14 -> 16张10*10

    return 0;
}
