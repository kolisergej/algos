#ifndef ALGOTESTS_H
#define ALGOTESTS_H

#include "gtest/gtest.h"

class AlgoTests : public ::testing::Test {

protected:
    // You can do set-up work for each test here.
    AlgoTests();

    // You can do clean-up work that doesn't throw exceptions here.
    virtual ~AlgoTests();

    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:

    // Code here will be called immediately after the constructor (right
    // before each test).
    virtual void SetUp();

    // Code here will be called immediately after each test (right
    // before the destructor).
    virtual void TearDown();
};

#endif // ALGOTESTS_H
