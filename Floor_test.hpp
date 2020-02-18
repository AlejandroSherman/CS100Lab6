#ifndef _FLOOR_TEST_HPP
#define _FLOOR_TEST_HPP
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
#include "Floor.hpp"
#include "Pow.hpp"



TEST(FloorTest, BasicTest1) {

	Op* op1 = new Op(2.5);

  Floor* test = new Floor(op1);

	EXPECT_EQ(test->evaluate(), 2);
}

TEST(FloorTest, BasicTest2) {

	Op* op1 = new Op(3);

  Floor* test = new Floor(op1);

	EXPECT_EQ(test->evaluate(), 3);
}

TEST(FloorTest, BasicTest3) {

	Op* op1 = new Op(-5.4);

  Floor* test = new Floor(op1);

	EXPECT_EQ(test->evaluate(), -6);
}

TEST(FloorTest, BasicTest4) {

	Op* op1 = new Op(0);

  Floor* test = new Floor(op1);

	EXPECT_EQ(test->evaluate(), 0);
}

TEST(FloorTest, LongTest) {

	Op* op1 = new Op(-5);
	Op* op2 = new Op(2);
	Pow* pow1 = new Pow(op1, op2);

	Op* op3 = new Op(4);
	Op* op4 = new Op(9);
	Mult* mult1 = new Mult(op3, op4);

	Add* add1 = new Add(pow1, mult1);

	Op* op5 = new Op(17);

	Sub* sub1 = new Sub(add1, op5);

  Floor* test = new Floor(sub1);

	EXPECT_EQ(test->evaluate(), 44);
}

#endif
