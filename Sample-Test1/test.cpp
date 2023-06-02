#include "pch.h"
#include"../Project3/Checker.cpp"

TEST(TestCaseName, CheckLength1) {
  EXPECT_EQ(60, Checker().getStringLength("ASD", "DSA"));
}

TEST(TestCaseName, CheckLength2) {
	EXPECT_EQ(0, Checker().getStringLength("A", "BB"));
}

TEST(TestCaseName, CheckLength3) {
	EXPECT_EQ(53, Checker().getStringLength("AAABB", "BAA"));
}

TEST(TestCaseName, CheckLength4) {
	EXPECT_EQ(53, Checker().getStringLength("AA", "AAA"));
}