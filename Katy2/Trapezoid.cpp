#include "Trapezoid.h"

double Trapezoid::CalculateSquare()
{
    return (((smallerBase + largeBase) / 2) * (sqrt(pow(leftSide, 2)
		- pow(((pow(smallerBase - largeBase, 2) + pow(leftSide, 2)
			- pow(rightSide, 2)) / (2 * smallerBase - 2 * largeBase)), 2))));
}

double Trapezoid::CalculatePerimeter()
{
	return largeBase +smallerBase + rightSide + leftSide;
}

std::string Trapezoid::GetInfo()
{
	return "Trapezoid: Square =  " + std::to_string(CalculateSquare()) + ", Perimetr = " + std::to_string(CalculatePerimeter()) + "\n";
}

double Trapezoid::GetLargeBase()
{
	return largeBase;
}

double Trapezoid::GetSmallerBase()
{
	return smallerBase;
}

double Trapezoid::GetRightSide()
{
	return rightSide;
}

double Trapezoid::GetLeftSide()
{
	return leftSide;
}
