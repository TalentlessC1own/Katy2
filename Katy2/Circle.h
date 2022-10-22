#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include "Figure.h"
#include <string>
class Circle :
    public Figure
{
private:
    double radius;

public:
    Circle(double radiusValue)
        :radius(radiusValue)
    {}
    
    double CalculateSquare() override;

    double CalculatePerimeter() override;

    std::string GetInfo() override;

    double GetRadius();
};

