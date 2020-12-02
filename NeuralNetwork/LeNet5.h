#pragma once
#include <iostream>
#include <vector>
#include "Input.h"
#include "Output.h"
#include "Hidden.h"
using namespace std;
class LeNet5 {
private:
	vector<vector<double>> image;
	int t = 1655;
public:
	LeNet5();
	LeNet5(vector<vector<double>> image);

	int initLeNet5();

};