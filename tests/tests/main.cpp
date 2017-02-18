#include <iostream>
#include <vector>
#include <array>
#include <functional>
#include <random>
#include <map>


#include "base.h"

using namespace std;

int main(int argc, char** argv) {

    ::testing::InitGoogleTest(&argc, argv);
    const int ret = RUN_ALL_TESTS();
    return ret;
}

