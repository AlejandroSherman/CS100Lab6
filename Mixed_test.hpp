#ifndef _MIXED_TEST_HPP_
#define _MIXED_TEST_HPP_
using namespace std;

#include "base.hpp"
#include "op.hpp"
#include "add.hpp"
#include "Sub.hpp"
#include "Div.hpp"
#include "mult.hpp"
#include <iostream>
#include "BubbleSort.hpp"
#include "sort.hpp"
#include "Parenthesies.hpp"
#include "Ceiling.hpp"
#include "Floor.hpp"
#include "Truncate.hpp"
#include "Abs.hpp"
#include "Pow.hpp"

TEST(MixedTestSet, ComplexTest1) {

	Op* op2 = new Op(2);
	Op* op3pt2 = new Op(3.2);
	Op* op4 = new Op(4);
	Op* opneg6 = new Op(-6);
	Op* oppt5 = new Op(0.5);
	Op* op36 = new Op(36);


	Abs* abs1 = new Abs(opneg6);
	Pow* pow1 = new Pow(abs1, op2);
	Add* add1 = new Add(op2, op4);
	Sub* sub1 = new Sub(add1, op36);

	Floor* floor1 = new Floor(op3pt2);
	Mult* mult1 = new Mult(sub1, oppt5);
	Mult* mult2 = new Mult(mult1, floor1);
	Ceil* test = new Ceil(mult2);
	

	EXPECT_EQ(test->evaluate(), -45);
}


TEST(MixedTestSet, ComplexTest2) {

	Op* op1 = new Op(1);
	Op* op2 = new Op(2);
	Op* op3 = new Op(3);
	Op* op6 = new Op(6);

	Sub* sub1 = new Sub(op2, op1);
	Paren* p1 = new Paren(sub1);

	Add* add1 = new Add(op6, op3);
	Paren* p2 = new Paren(add1);

	Mult* mult1 = new Mult(p1, p2);
	Trunc* t1 = new Trunc(sub1);

	Sub* test = new Sub(mult1, t1);
	string result = "(2 - 1) * (6 + 3) - 1"; // truncate(2-1) = 1

	EXPECT_EQ(test->stringify(), result);
}

#endif
