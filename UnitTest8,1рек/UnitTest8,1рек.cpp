#include "pch.h"
#include "CppUnitTest.h"
#include "../lab8.1pek/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest81рек
{
	TEST_CLASS(UnitTest81рек)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const char* str3 = "aabbcc";
			Assert::AreEqual(CountRecursive(str3, 0, false), 3);
		}
	};
}
