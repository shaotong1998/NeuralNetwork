#include "Util.h"

Util::Util()
{
}

vector<vector<double>> Util::getFilter()
{
    int length = 5;//filter±ß³¤Îª5
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
    printFilter(filter);
    return filter;
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
