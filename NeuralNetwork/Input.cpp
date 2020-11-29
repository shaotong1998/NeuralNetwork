#include "Input.h"

Input::Input()
{
}

Input::Input(vector<vector<int>> image)
{
	this->image = image;
}

vector<vector<int>> Input::getInput()
{
	return this->image;
}
