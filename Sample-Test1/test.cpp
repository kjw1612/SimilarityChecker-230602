#include "pch.h"
#include"../Project3/Checker.cpp"

TEST(TestCaseName, CheckLength) {
  EXPECT_EQ(60, Checker().getStringLength("ASD", "DSA"));
  EXPECT_EQ(0, Checker().getStringLength("A", "BB"));
  EXPECT_EQ(60, Checker().getStringLength("AAABB", "BAA"));
  EXPECT_EQ(60, Checker().getStringLength("AA", "AAA"));
}