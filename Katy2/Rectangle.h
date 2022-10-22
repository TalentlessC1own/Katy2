#pragma once
#include "Figure.h"
#include <string>
class Rectangle :
    public Figure
{
private:
    double width;
    double height;
public:
    Rectangle(double widthValue, double heightValue)
        : width(widthValue), height(heightValue)
    {}
    double CalculateSquare() override;

    double CalculatePerimeter() override;

    std::string GetInfo() override;

    double GetWidth();

    double GetHeight();
};

