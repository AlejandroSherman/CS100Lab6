#ifndef __PARENTHESIES_TEST_HPP
#define __PARENTHESIES_TEST_HPP
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
#include "Parenthesies.hpp"
#include "Pow.hpp"
#include "Div.hpp"

TEST(ParenthesiesTest, BasicTest1) {

	Op* op1 = new Op(2.5);
  Op* op2 = new Op(1);
  Sub* sub1 = new Sub(op1, op2);

  Paren* test = new Paren(sub1);
  string result = "(2.5 - 1)";

	EXPECT_EQ(test->stringify(), result);
}

TEST(ParenthesiesTest, BasicTest2) {

	Op* op1 = new Op(2.5);
  Op* op2 = new Op(1);
  Pow* pow1 = new Pow(op1, op2);


  Paren* test = new Paren(pow1);
  string result = "(2.5 ** 1)";

	EXPECT_EQ(test->stringify(), result);
}

TEST(ParenthesiesTest, ParenRightSide) {

	Op* op1 = new Op(2.5);
  Op* op2 = new Op(1);
  Op* op3 = new Op(5);
  Sub* sub1 = new Sub(op1, op2);
  Paren* p1 = new Paren(sub1);

  Mult* test = new Mult(op3, p1);

  string result = "5 * (2.5 - 1)";

	EXPECT_EQ(test->stringify(), result);
}

TEST(ParenthesiesTest, ParenLeftSide) {

  Op* op1 = new Op(2.5);
  Op* op2 = new Op(1);
  Op* op3 = new Op(10);
  Div* div1 = new Div(op1, op2);
  Paren* p1 = new Paren(div1);

  Add* test = new Add(p1, op3);

  string result = "(2.5 / 1) + 10";


	EXPECT_EQ(test->stringify(), result);
}


TEST(ParenthesiesTest, ComplicatedTest) {

	Op* op1 = new Op(2);
	Op* op2 = new Op(4);
  Op* op3 = new Op(-5);

  Add* add1 = new Add(op1, op2);
  Paren* p1 = new Paren(add1);
	Pow* pow1 = new Pow(op3, p1);

	Op* op4 = new Op(9);

	Mult* mult1 = new Mult(pow1, op4);

	Op* op5 = new Op(17);

	Sub* test = new Sub(mult1, op5);

  string result = "-5 ** (2 + 4) * 9 - 17";

	EXPECT_EQ(test->stringify(), result);
}

#endif
