#pragma once
#include <iostream>
class Figure
{
public:

	virtual double CalculateSquare() = 0;

	virtual double CalculatePerimeter() = 0;

	virtual std::string GetInfo() = 0;

	virtual ~Figure() = default;
};

