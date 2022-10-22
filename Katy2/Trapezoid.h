#pragma once
#include "Figure.h"
#include <string>
class Trapezoid :
    public Figure
{
private:
    double largeBase;
    double smallerBase;
    double rightSide;
    double leftSide;
public:
    Trapezoid(double smallerBaseValue, double largeBaseValue, double rightSideValue, double leftSideValue)
        : smallerBase(smallerBaseValue), largeBase(largeBaseValue), rightSide(rightSideValue),leftSide(leftSideValue)
    {}
    double CalculateSquare() override;

    double CalculatePerimeter() override;

    std::string GetInfo() override;

    double GetLargeBase();

    double GetSmallerBase();

    double GetRightSide();

    double GetLeftSide();
};

