#include "testConsts.hpp"
#include "testMove.hpp"

void TestConstants()
{
	TestConstants1();
	TestConstants2();
}

void TestMoveFunc()
{
	MoveTestWrapper res = testmove();
	MoveTestWrapper mtw = std::move(res);
}

int main()
{
	//TestConstants();
	TestMoveFunc();

	return 0;
}
