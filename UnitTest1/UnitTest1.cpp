#define _USE_MATH_DEFINES
#include <cmath>
#include "CppUnitTest.h"
#include "../Katy2/Circle.h"
#include "../Katy2/Circle.cpp"
#include "..\Katy2\Rectangle.h"
#include "..\Katy2\Rectangle.cpp"
#include "../Katy2/Trapezoid.h"
#include "../Katy2/Trapezoid.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	private:
		Circle cir1{ 15 };
		Circle cir2{ 2 };
		Circle cir3{ 9 };

		Trapezoid trap1{ 19.55,5.55,14.5,10.6 };
		Trapezoid trap2{ 8,4,3,5 };
		Trapezoid trap3{ 21,7,15,13 };

		Rectangle rec1{ 1.255,8 };
		Rectangle rec2{ 1.5,2 };
		Rectangle rec3{ 2,2 };
	public:

		TEST_METHOD(Test)
		{
			Assert::IsTrue((round(cir1.CalculateSquare() * 1000) / 1000) == 706.858);
			Assert::IsTrue((round(cir2.CalculateSquare() * 1000) / 1000) == 12.566);
			Assert::IsTrue((round(cir3.CalculateSquare() * 1000) / 1000) == 254.469);
			Assert::IsTrue((round(cir1.CalculatePerimeter() * 1000) / 1000) == 94.248);
			Assert::IsTrue((round(cir2.CalculatePerimeter() * 1000) / 1000) == 12.566);
			Assert::IsTrue((round(cir3.CalculatePerimeter() * 1000) / 1000) == 56.549);

			Assert::IsTrue((round(rec1.CalculateSquare() * 1000) / 1000) == 10.04);
			Assert::IsTrue((round(rec2.CalculateSquare() * 1000) / 1000) == 3);
			Assert::IsTrue((round(rec3.CalculateSquare() * 1000) / 1000) == 4);


			Assert::IsTrue((round(rec1.CalculatePerimeter() * 1000) / 1000) == 18.51);
			Assert::IsTrue(rec2.CalculatePerimeter() == 7);
			Assert::IsTrue(rec3.CalculatePerimeter() == 8);

			Assert::IsTrue((round(trap1.CalculateSquare() * 1000) / 1000) == 125.552);
			Assert::IsTrue(trap2.CalculateSquare() == 18);
			Assert::IsTrue(trap3.CalculateSquare() == 168);
			Assert::IsTrue(trap1.CalculatePerimeter() == 50.2);
			Assert::IsTrue(trap2.CalculatePerimeter() == 20);
			Assert::IsTrue(trap3.CalculatePerimeter() == 56);
		}
	};
}
