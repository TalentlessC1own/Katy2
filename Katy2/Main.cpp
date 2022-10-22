#include "Figure.h"
#include "Input.h"
#include"Output.h"
#include <vector>

enum class Options
{
	Show = 1,
	Add,
	FileOutput,
	Clear,
	Exit
};

enum class Type
{
	Console = 1,
	File
};


int main()
{
	std::cout << "katy var 5 kr 2 " << std::endl;

	std::vector <std::shared_ptr<Figure>> figureCase;

	while (true)
	{
		std::cout << "1 - Show figures\n2 - Add figures\n3 - File output\n4 - Clear list\n5 - Exit" << std::endl;

		Options choice = static_cast<Options>(CheckMenuItem(5));

		Type choiceT;

		switch (choice)
		{
		case Options::Show:
			if (figureCase.size() == 0)
			{
				std::cout << "First enter the shapes" << std::endl;
				continue;
			}
			for (int i = 0; i < figureCase.size(); i++)
				std::cout << figureCase[i]->GetInfo();
			break;
		case Options::Add:
			std::cout << "1 - Console input\n2 - File input" << std::endl;
			choiceT = static_cast<Type>(CheckMenuItem(2));
			switch (choiceT)
			{
			case Type::Console:
				AddFigureConsoleInput(figureCase);
				InitialDataOutput(figureCase);
				break;
			case Type::File:
				AddFigureFileInput(figureCase);
				break;
			}
			break;
		case Options::FileOutput:
			if (figureCase.size() == 0)
			{
				std::cout << "First enter the shapes" << std::endl;
				continue;
			}
			FileOutput(figureCase);
			break;
		case Options::Clear:
			figureCase.clear();
			break;
		case Options::Exit:
			return 0;
		}
	}
}