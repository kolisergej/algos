#include "algotests.h"

#include <random>

#include "reverseList.h"
#include "binarySearch.h"
#include "twoSumProblem.h"
#include "threeSumProblem.h"
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
    EXPECT_EQ(interval_map.getElement(30), initValue);
    EXPECT_EQ(interval_map.getElement(-10000), initValue);

    const int secondValue = -999;
    interval_map.setElement(10, 20, secondValue);
    EXPECT_EQ(interval_map.getElement(9), initValue);
    EXPECT_EQ(interval_map.getElement(10), secondValue);
    EXPECT_EQ(interval_map.getElement(11), secondValue);
    EXPECT_EQ(interval_map.getElement(19), secondValue);
    EXPECT_EQ(interval_map.getElement(20), initValue);
    EXPECT_EQ(interval_map.getElement(21), initValue);

    const int thirdValue = 555;
    interval_map.setElement(15, 25, thirdValue);
    EXPECT_EQ(interval_map.getElement(14), secondValue);
    EXPECT_EQ(interval_map.getElement(15), thirdValue);
    EXPECT_EQ(interval_map.getElement(16), thirdValue);
    EXPECT_EQ(interval_map.getElement(24), thirdValue);
    EXPECT_EQ(interval_map.getElement(25), initValue);
    EXPECT_EQ(interval_map.getElement(26), initValue);

    const int fourthValue = 666;
    interval_map.setElement(30, 31, fourthValue);
    EXPECT_EQ(interval_map.getElement(29), initValue);
    EXPECT_EQ(interval_map.getElement(30), fourthValue);
    EXPECT_EQ(interval_map.getElement(31), initValue);

    const int finalValue = 999;
    interval_map.setElement(-100, 1000, finalValue);
    EXPECT_EQ(interval_map.getElement(-101), initValue);
    EXPECT_EQ(interval_map.getElement(-100), finalValue);
    EXPECT_EQ(interval_map.getElement(-99), finalValue);
    EXPECT_EQ(interval_map.getElement(999), finalValue);
    EXPECT_EQ(interval_map.getElement(1000), initValue);
    EXPECT_EQ(interval_map.getElement(1001), initValue);

//    random_device rd;
//    mt19937 gen(rd());
//    uniform_int_distribution<> dist1(-100000, 1000);
//    uniform_int_distribution<> dist2(1001, 100000);
//    uniform_int_distribution<> dist3(-100000, 100000);
//    for (int index = 0; index < 100000000; ++index) {
//        auto firstBound = dist1(gen);
//        auto secondBound = dist2(gen);
//        auto value = dist3(gen);
//        interval_map.setElement(firstBound, secondBound, value);
//    }
}

TEST_F(AlgoTests, ThreeSumTest) {
    EXPECT_EQ(threeSumSolve({-1,0,1}), vector<vector<int>>({{-1,0,1}}));
    EXPECT_EQ(threeSumSolve({-1,-1,0,0,1,1,1,1}), vector<vector<int>>({{-1,0,1}}));
    EXPECT_EQ(threeSumSolve({-1,-1,0,0,0,1,1,1,1}), vector<vector<int>>({{-1,0,1},{0,0,0}}));
    EXPECT_EQ(threeSumSolve({9,4,3,6,0,-1,5,6,-15,3,9,2}), vector<vector<int>>({{ -15, 6, 9 }}));
}

TEST_F(AlgoTests, ReverseListTest) {
    Node* a = new Node{1, new Node{2, new Node{3, new Node{4, new Node{5, nullptr}}}}};
    a = reverseList(a);

    EXPECT_EQ(a->val, 5);
    EXPECT_EQ(a->pNext->val, 4);
    EXPECT_EQ(a->pNext->pNext->val, 3);
    EXPECT_EQ(a->pNext->pNext->pNext->val, 2);
    EXPECT_EQ(a->pNext->pNext->pNext->pNext->val, 1);

    freeList(a);
}
