#include "Output.h"

void ConsoleOutput(std::vector<std::shared_ptr<Figure>>& figureCase)
{
	for (int i = 0; i < figureCase.size(); i++)
		figureCase[i]->GetInfo();
}

void FileOutput(std::vector<std::shared_ptr<Figure>>& figureCase)
{
	std::ofstream fileRecorder = CheckFileOutput();

	for (int i = 0; i < figureCase.size(); i++)
	{
		fileRecorder <<  figureCase[i]->GetInfo();
	}

}

void InitialDataOutput(std::vector<std::shared_ptr<Figure>>& figureCase)
{
	std::cout << "Save initial data ?\n1 - Yes\n2 - No" << std::endl;
	if (CheckMenuItem(2) != 1)
		return;
	std::ofstream fileRecorder = CheckFileOutput();

	std::string cirleMark = "Circle";
	std::string rectangleMark = "Rectangle";
	std::string trapezoidMark = "Trapezoid";

	fileRecorder << figureCase.size() << std::endl;

	for (int i = 0; i < figureCase.size(); i++)
	{
		std::string name =  typeid(*figureCase[i]).name();
		if (name == typeid(Circle).name())
		{
			fileRecorder << cirleMark << std::endl;;
			fileRecorder << std::static_pointer_cast<Circle>(figureCase[i])->GetRadius() << std::endl;
		}
		else if (name == typeid(Rectangle).name())
		{
			fileRecorder << rectangleMark << std::endl;

			fileRecorder << std::static_pointer_cast<Rectangle>(figureCase[i])->GetWidth() << std::endl;

			fileRecorder << std::static_pointer_cast<Rectangle>(figureCase[i])->GetHeight() << std::endl;
		}
		else if (name == typeid(Trapezoid).name())
		{
			fileRecorder << trapezoidMark << std::endl;

			fileRecorder << std::static_pointer_cast <Trapezoid>(figureCase[i])->GetSmallerBase() << std::endl;

			fileRecorder << std::static_pointer_cast <Trapezoid>(figureCase[i])->GetLargeBase() << std::endl;

			fileRecorder << std::static_pointer_cast <Trapezoid>(figureCase[i])->GetRightSide() << std::endl;

			fileRecorder << std::static_pointer_cast <Trapezoid>(figureCase[i])->GetLeftSide() << std::endl;

		}

	}
	fileRecorder.close();
}

