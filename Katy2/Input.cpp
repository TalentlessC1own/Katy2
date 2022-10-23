#include "Input.h"
#include "Figure.h"

void AddFigureConsoleInput(std::vector<std::shared_ptr<Figure>>& figureCase)
{
	double radiusValue = 0;
	double widthValue = 0;
	double heightValue = 0;

	std::cout << "1 - Circle\n2 - Rectangle\n3 - Trapezoid" << std::endl;
	FiguresTypes type = static_cast<FiguresTypes>(CheckMenuItem(3));
	while (true)
	{
		switch (type)
		{
		case FiguresTypes::Circle:
			std::cout << "Enter radius." << std::endl;
			radiusValue = CheckDoubleValue();

			figureCase.emplace_back(std::make_shared<Circle>(radiusValue));
			return;
		case FiguresTypes::Rectangle:
			std::cout << "Enter width." << std::endl;
			widthValue = CheckDoubleValue();

			std::cout << "Enter height." << std::endl;
			heightValue = CheckDoubleValue();

			figureCase.emplace_back(std::make_shared<Rectangle>(widthValue, heightValue));

			return;
		case FiguresTypes::Trapezoid:
			std::cout << "Enter smaller base" << std::endl;
			double smallerBaseValue = CheckDoubleValue();

			std::cout << "Enter large base " << std::endl;
			double largeBaseValue;
			while (true)
			{
				largeBaseValue = CheckDoubleValue();
				if (largeBaseValue <= smallerBaseValue)
				{
					std::cout << "Large base must be greater than the smaller base" << std::endl;
					continue;
				}
				break;
			}

			std::cout << "Enter right side" << std::endl;
			double rightSideValue = CheckDoubleValue();

			std::cout << "Enter left side" << std::endl;
			double leftSideValue = CheckDoubleValue();

			std::vector <double> trapezoidParts = { smallerBaseValue ,largeBaseValue , rightSideValue,leftSideValue };

			if (CheckTrapezoid(trapezoidParts))
				figureCase.emplace_back(std::make_shared<Trapezoid>(smallerBaseValue, largeBaseValue, rightSideValue, leftSideValue));
			else
			{
				std::cout << "Incorect data" << std::endl;
				continue;
			}
			return;
		}
	}
}

void AddFigureFileInput(std::vector<std::shared_ptr<Figure>>& figureCase)
{
	std::string fileName = "";
	std::ifstream file;

	file.exceptions(std::ifstream::badbit | std::ifstream::failbit);
	while (true)
	{
		std::cout << "Enter file name. " << std::endl << "ENTER : ";
		std::cin >> fileName;
		try
		{
			file.open(fileName);
			std::cout << "Sucefull file open " << std::endl;
		}
		catch (const std::exception&)
		{
			std::cout << "Incorrect file name or way.Try again ." << std::endl;
			continue;

		}

		std::string cirleMark = "Circle";
		std::string rectangleMark = "Rectangle";
		std::string trapezoidMark = "Trapezoid";
		int count;
		std::string typeMark;

		try
		{
			count = CheckLineInt(file);
			for (int i = 0; i < count; i++)
			{
				typeMark = CheckLineString(file);
				if (typeMark == cirleMark)
				{
					figureCase.emplace_back(std::make_shared<Circle>(CheckLineDouble(file)));
				}
				else if(typeMark == rectangleMark)
				{
					figureCase.emplace_back(std::make_shared<Rectangle>(CheckLineDouble(file), CheckLineDouble(file)));
				}
				else if (typeMark == trapezoidMark)
				{
					std::vector<double> trapezoidParts;
					for (int  j = 0; j < 4; j++)
					{
						trapezoidParts.emplace_back(CheckLineDouble(file));
					}
					if (CheckTrapezoid(trapezoidParts))
						figureCase.emplace_back(std::make_shared<Trapezoid>(trapezoidParts[0], trapezoidParts[1], trapezoidParts[2], trapezoidParts[3]));
				}
			}
		}
		catch (std::invalid_argument iaex)
		{
			std::cout << "Incorect data " << std::endl;
			file.close();
			continue;
		}

		file.close();
		break;
	}

}