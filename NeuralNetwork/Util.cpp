#include "Util.h"

Util::Util()
{
}

vector<vector<double>> Util::getFilter()
{
    int length = 5;//filter边长为5
    vector<vector<double>> filter(length);
    for (int i = 0; i < filter.size(); i++) {
        filter[i].resize(length);
    }

    for (int i = 0; i < filter.size(); i++) {
        for (int j = 0; j < filter[i].size(); j++) {
            if (j == 2) {
                filter[i][j] = 1;
            }
        }
    }
    //printFilter(filter);
    return filter;
}

vector<vector<double>> Util::getWeight()
{
    int length = 5;//filter边长为5
    vector<vector<double>> weight(length);
    for (int i = 0; i < weight.size(); i++) {
        weight[i].resize(length);
    }

    for (int i = 0; i < weight.size(); i++) {
        for (int j = 0; j < weight[i].size(); j++) {
            weight[i][j] = rand() * (2. / RAND_MAX) - 1;

        }
    }
   // printFilter(weight);
    return weight;
}

void Util::printFilter(vector<vector<double>> v)
{
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

double Util::matrixInnerProduct(vector<vector<double>> a, vector<vector<double>> b)
{
    //int length = a.size();
    double result = 0;
    if (a.size() != b.size()) {
        cout << "算不了，下一个！" << endl;
    }
    //做内积简单很多
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a.size(); j++) {
            result = a[i][j] * b[i][j] + result;
        }
    }
    return result;
}

double Util::sigmoid(double x)
{
    return 1/(1+exp(-x));
}
