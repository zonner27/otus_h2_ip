
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

BOOST_AUTO_TEST_CASE(test_filter_1)
{

    std::vector<std::vector<std::string>> ip_test = {{"2","2","2","2"}, {"1","1","1","1"}, {"5","5","5","5"}};
    std::vector<std::vector<std::string>> result = {{"1","1","1","1"}};
    std::vector<std::vector<std::string>> ip_temp;

    std::for_each(ip_test.begin(), ip_test.end(), [&ip_temp](auto &strv){ if (ipfilter(strv, "1")) ip_temp.push_back(strv); });
    BOOST_REQUIRE(ip_temp == result);

}

BOOST_AUTO_TEST_CASE(test_filter_46_70)
{

    std::vector<std::vector<std::string>> ip_test = {{"46","5","2","2"}, {"46","70","1","1"}, {"5","70","5","5"}};
    std::vector<std::vector<std::string>> result = {{"46","70","1","1"}};
    std::vector<std::vector<std::string>> ip_temp;

    std::for_each(ip_test.begin(), ip_test.end(), [&ip_temp](auto &strv){ if (ipfilter(strv, "46", "70")) ip_temp.push_back(strv); });
    BOOST_REQUIRE(ip_temp == result);

}

BOOST_AUTO_TEST_CASE(test_filter_46_any)
{

    std::vector<std::vector<std::string>> ip_test = {{"5","46","2","2"}, {"46","70","1","1"}, {"5","70","5","5"}};
    std::vector<std::vector<std::string>> result = {{"5","46","2","2"}, {"46","70","1","1"}};
    std::vector<std::vector<std::string>> ip_temp;

    std::for_each(ip_test.begin(), ip_test.end(), [&ip_temp](auto &strv){ if (ipfilter_any(strv, "46")) ip_temp.push_back(strv); });
    BOOST_REQUIRE(ip_temp == result);

}

BOOST_AUTO_TEST_SUITE_END()
