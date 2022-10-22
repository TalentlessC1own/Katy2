#pragma once
#include "Figure.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Trapezoid.h"
#include <vector>
#include "InputCheck.h"
#include "CheckFile.h"

void ConsoleOutput(std::vector<std::shared_ptr<Figure>>& figureCase);

void FileOutput(std::vector<std::shared_ptr<Figure>>& figureCase);

void InitialDataOutput(std::vector<std::shared_ptr<Figure>>& figureCase);