#ifndef LIB201516072019_H
#define LIB201516072019_H

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>


void print(std::vector<std::vector<std::string>> ip_pool);

std::vector<std::string> split(const std::string &str, char d);

bool ipcomparison(std::vector<std::string> str1, std::vector<std::string> str2);

bool ipfilter(std::vector<std::string> strv, std::string str);

bool ipfilter(std::vector<std::string> strv, std::string str0, std::string str1);

bool ipfilter_any(std::vector<std::string> strv, std::string str);


#endif // LIB201516072019_H
