#include "pch.h"  
#include "CppUnitTest.h"
#include "../app/money.h"
#include <sstream>
#include <string>
#include "../app/money.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace vsite::oop::v7;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(AddCents)
		{
			money m1(1, 11);
			money m2(6, 85);
			m1 += m2;

			std::stringstream ss;
			ss << m1;
			Assert::IsTrue(ss.str() == "7 eur 96 ct");

			money m3(-1, -11);
			money m4(6, 85);
			m3 += m4;

			std::stringstream ss2;
			ss2 << m3;
			Assert::IsTrue(ss2.str() == "5 eur 74 ct");
		}

		TEST_METHOD(SubtractCents)
		{
			money m1(1, 11);
			money m2(6, 85);
			m1 -= m2;

			std::stringstream ss;
			ss << m1;
			Assert::IsTrue(ss.str() == "-5 eur 74 ct");

			money m3(-1, -11);
			money m4(6, 85);
			m3 -= m4;

			std::stringstream ss2;
			ss2 << m3;
			Assert::IsTrue(ss2.str() == "-7 eur 96 ct");
		}

		TEST_METHOD(OutputTest)
		{
			money m1(1, 10);
			money m2(2, 95);
			m1 += m2;

			std::stringstream ss1;
			ss1 << m1;
			Assert::IsTrue(ss1.str() == "4 eur 05 ct");

			money m3(1, 10);
			money m4(1, 10);
			m3 -= m4;

			std::stringstream ss2;
			ss2 << m3;
			Assert::IsTrue(ss2.str() == "0 eur 00 ct");

			money m5(-1, -10);
			money m6(1, 10);
			m5 -= m6;

			std::stringstream ss3;
			ss3 << m5;
			Assert::IsTrue(ss3.str() == "-2 eur 20 ct");
		}

		TEST_METHOD(InputTest)
		{
			std::stringstream ss("3 25");
			money m;
			ss >> m;

			std::stringstream out;
			out << m;
			Assert::IsTrue(out.str() == "3 eur 25 ct");
		}
	};
}
