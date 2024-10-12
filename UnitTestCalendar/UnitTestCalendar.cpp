#include "pch.h"
#include "CppUnitTest.h"
#include "../Calendar/Calendar.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestCalendar
{
	TEST_CLASS(UnitTestCalendar)
	{
	public:
		
		TEST_METHOD(TestLeapYear_2020_True)
		{Assert::IsTrue(leapYear(2020), L"2020 - високосный год");
		}

		TEST_METHOD(TestLeapYear_1984_True) {
			Assert::IsTrue(leapYear(1984), L"1984 - високосный год");
		}

		TEST_METHOD(TestLeapYear_2021_False) {
			Assert::IsFalse(leapYear(2021), L"2021 - не високосный год");
		}

		
	};
}
