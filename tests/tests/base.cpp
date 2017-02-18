#include "base.h"

#include "reverseList.h"
#include "binarySearch.h"
#include "sumProblem.h"


AlgoTests::AlgoTests() {}

AlgoTests::~AlgoTests() {}

void AlgoTests::SetUp() {}

void AlgoTests::TearDown() {}

TEST_F(AlgoTests, 2SumProblemTest)
{
    const vector<int> input {1,2,3,4,5,6,7,8,9,10};
    EXPECT_EQ(hasPairSumOf(input, 20), false);
    EXPECT_EQ(hasPairSumOf(input, 6), true);
}

TEST_F(AlgoTests, BinarySearchTest)
{
    const vector<int> input {5,4,3,2,1,0,1,2,3,4,5};
    EXPECT_EQ(binarySearch(input), 5);
}
