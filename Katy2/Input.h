#pragma once
#include "Figure.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Trapezoid.h"
#include <vector>
#include "InputCheck.h"

enum class FiguresTypes
{
	Circle = 1,
	Rectangle,
	Trapezoid
};

void AddFigureConsoleInput(std::vector<std::shared_ptr<Figure>>& figureCase);

void AddFigureFileInput(std::vector<std::shared_ptr<Figure>>& figureCase);

