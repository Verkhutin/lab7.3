#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab7.3/lab7.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest73
{
	TEST_CLASS(UnitTest73)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int r = 3, c = 2;
			int** T = new int* [r];
			for (int i = 0; i < r; i++)
				T[i] = new int[c];

			T[0][0] = 1; T[0][1] = 0;
			T[1][0] = 1; T[1][1] = 1;
			T[2][0] = 1; T[2][1] = 1;

			int t = Amount(T, r, c);
			Assert::AreEqual(t, 1);
		}
	};
}
