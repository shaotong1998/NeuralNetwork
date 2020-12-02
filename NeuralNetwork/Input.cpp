#include "Input.h"

Input::Input()
{
}

Input::Input(vector<vector<double>> image)
{
	this->image = image;
}

vector<vector<double>> Input::getInput()
{
	return this->image;
}
