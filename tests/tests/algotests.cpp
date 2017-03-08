#include "algotests.h"

#include "reverseList.h"
#include "binarySearch.h"
#include "sumProblem.h"
#include "interval_map.h"
#include "queue.h"

AlgoTests::AlgoTests() {}

AlgoTests::~AlgoTests() {}

void AlgoTests::SetUp() {}

void AlgoTests::TearDown() {}

TEST_F(AlgoTests, 2SumProblemTest) {
    const vector<int> input {1,2,3,4,5,6,7,8,9,10};
    EXPECT_FALSE(hasPairSumOf(input, 20));
    EXPECT_TRUE(hasPairSumOf(input, 6));
}

TEST_F(AlgoTests, BinarySearchTest) {
    EXPECT_EQ(binarySearch({8,7,6,5,4,3,2,1,0,1,2,3,4,5}), 8);
    EXPECT_EQ(binarySearch({8,7,6,5,0,1}), 4);
    EXPECT_EQ(binarySearch({8,0,1,2,3,4}), 1);
    EXPECT_EQ(binarySearch({5,4,3,2,1,0}), -1);
    EXPECT_EQ(binarySearch({0,1,2,3,4,5}), -1);
}

TEST_F(AlgoTests, QueueTest) {
    my_queue<int> q;
    EXPECT_TRUE(q.empty());
    EXPECT_THROW(q.pop_front(), std::runtime_error);
    q.push_back(1);
    q.push_back(2);
    q.push_back(3);
    q.push_back(4);
    q.push_back(5);
    q.push_back(6);
    EXPECT_EQ(q.size(), 6);
    EXPECT_EQ(q.pop_front(), 1);
    EXPECT_EQ(q.size(), 5);
    EXPECT_EQ(q.pop_front(), 2);
    EXPECT_EQ(q.pop_front(), 3);
    EXPECT_EQ(q.pop_front(), 4);
    q.push_back(7);
    q.push_back(8);
    EXPECT_EQ(q.size(), 4);
    EXPECT_EQ(q.pop_front(), 5);
    EXPECT_EQ(q.pop_front(), 6);
    EXPECT_EQ(q.pop_front(), 7);
    EXPECT_EQ(q.pop_front(), 8);
    EXPECT_TRUE(q.empty());
    EXPECT_THROW(q.pop_front(), std::runtime_error);
}

TEST_F(AlgoTests, IntervalMapTest) {
    const int initValue = 100;
    IntervalMap<int> interval_map(initValue);
    EXPECT_TRUE(interval_map.size() == 1);
    EXPECT_EQ(interval_map.getElement(30), initValue);
    EXPECT_EQ(interval_map.getElement(-10000), initValue);




}
