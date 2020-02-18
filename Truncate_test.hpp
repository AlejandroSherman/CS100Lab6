#ifndef _TRUNCATE_TEST_HPP
#define _TRUNCATE_TEST_HPP
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
#include "Truncate.hpp"
#include "Pow.hpp"
#include "Div.hpp"

TEST(TruncateTest, BasicTest1) {

	Op* op1 = new Op(2.5);
  Op* op2 = new Op(1);
  Sub* sub1 = new Sub(op1, op2);

  Trunc* test = new Trunc(sub1);
  string result = "1.5";

	EXPECT_EQ(test->stringify(), result);
}

TEST(TruncateTest, BasicTest2) {

	Op* op1 = new Op(2.5);
  Op* op2 = new Op(1);
  Pow* pow1 = new Pow(op1, op2);


  Trunc* test = new Trunc(pow1);
  string result = "2.5";

	EXPECT_EQ(test->stringify(), result);
}

TEST(TruncateTest, TruncateRightSide) {

	Op* op1 = new Op(2.5);
  Op* op2 = new Op(1);
  Op* op3 = new Op(5);
  Sub* sub1 = new Sub(op1, op2);
  Trunc* t1 = new Trunc(sub1);

  Mult* test = new Mult(op3, t1);

  string result = "5 * 1.5";

	EXPECT_EQ(test->stringify(), result);
}

TEST(TruncateTest, TruncateLeftSide) {

  Op* op1 = new Op(2.5);
  Op* op2 = new Op(1);
  Op* op3 = new Op(10);
  Div* div1 = new Div(op1, op2);
  Trunc* t1 = new Trunc(div1);

  Add* test = new Add(t1, op3);

  string result = "2.5 + 10";


	EXPECT_EQ(test->stringify(), result);
}


TEST(TruncateTest, ComplicatedTest) {

	Op* op1 = new Op(-5);
	Op* op2 = new Op(2);
	Pow* pow1 = new Pow(op1, op2);

	Op* op3 = new Op(4);
	Op* op4 = new Op(9);
	Mult* mult1 = new Mult(op3, op4);

	Add* add1 = new Add(pow1, mult1);

	Op* op5 = new Op(17);

	Sub* sub1 = new Sub(add1, op5);

  Trunc* test = new Trunc(sub1);
  string result = "44";

	EXPECT_EQ(test->stringify(), result);
}

#endif
