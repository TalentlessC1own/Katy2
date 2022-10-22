#include "Circle.h"

double Circle::CalculateSquare()
{
	return M_PI * radius * radius;
}

double Circle::CalculatePerimeter()
{
	return 2 * M_PI * radius;
}

std::string Circle::GetInfo()
{
	return "Circle: Square =  " + std::to_string(CalculateSquare()) + ", Perimetr = " + std::to_string(CalculatePerimeter()) + "\n";
}

double Circle::GetRadius()
{
	return radius;
}
