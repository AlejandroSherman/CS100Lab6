#ifndef _ABS_TEST_HPP
#define _ABS_TEST_HPP
using namespace std;

#include "VectorContainer.hpp"
#include "base.hpp"
#include "op.hpp"
#include "add.hpp"
#include "Sub.hpp"
#include "mult.hpp"
#include <iostream>
#include "BubbleSort.hpp"
#include "sort.hpp"
#include "Abs.hpp"
#include "Pow.hpp"

TEST(AbsTest, BasicTest1) {

	Op* op1 = new Op(-5);
	Op* op2 = new Op(2);
	Pow* pow1 = new Pow(op1, op2);

	Op* op3 = new Op(4);
	Op* op4 = new Op(9);
	Mult* mult1 = new Mult(op3, op4);

	Add* add1 = new Add(pow1, mult1);

	Op* op5 = new Op(17);

	Sub* sub1 = new Sub(add1, op5);

  Abs* test = new Abs(sub1);

	EXPECT_EQ(test->evaluate(), 44);
}


TEST(AbsTest, BasicTest2) {

	Op* op1 = new Op(-2.5);

  Abs* test = new Abs(op1);

	EXPECT_EQ(test->evaluate(), 2.5);
}

#endif
