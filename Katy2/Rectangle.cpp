#include "Rectangle.h"

double Rectangle::CalculateSquare()
{
    return width * height;
}

double Rectangle::CalculatePerimeter()
{
    return (height + width) * 2;
}

std::string Rectangle::GetInfo()
{
    return "Rectangle: Square =  " + std::to_string(CalculateSquare()) + ", Perimetr = " + std::to_string(CalculatePerimeter()) + "\n";
}

double Rectangle::GetWidth()
{
    return width;
}

double Rectangle::GetHeight()
{
    return height;
}
