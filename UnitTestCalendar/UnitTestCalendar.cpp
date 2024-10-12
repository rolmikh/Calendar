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

		TEST_METHOD(TestfirstDayOfMonth_10_2024_AreEqual) {
			Assert::AreEqual(1, firstDayOfMonth(10, 2024), L"Ожидалось, что 1 октября 2024 будет вторником");
		}

		TEST_METHOD(TestfirstDayOfMonth_2_2024_AreEqual) {
			Assert::AreEqual(3, firstDayOfMonth(2, 2024), L"Ожидалось, что 1 февраля 2024 будет четверг");
		}
		
	};
}
