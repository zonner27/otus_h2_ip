
#define BOOST_TEST_MODULE test_main

#include "lib.h"
#include <vector>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_main)

BOOST_AUTO_TEST_CASE(test_sort)
{

    std::vector<std::vector<std::string>> ip_test = {{"2","2","2","2"}, {"1","1","1","1"}, {"5","5","5","5"}};
    std::vector<std::vector<std::string>> result = {{"5","5","5","5"}, {"2","2","2","2"}, {"1","1","1","1"}};

    std::sort(ip_test.begin(), ip_test.end(), ipcomparison);
    BOOST_REQUIRE(ip_test == result);
}

BOOST_AUTO_TEST_SUITE_END()
