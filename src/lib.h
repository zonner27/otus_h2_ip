#ifndef LIB201516072019_H
#define LIB201516072019_H

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>

using ip_adress = std::tuple<uint8_t, uint8_t, uint8_t, uint8_t>;

std::vector<std::string> split(const std::string &str, char d);
ip_adress ipget(const std::vector<std::string> &strv);
void print2(const std::vector<ip_adress> &ipv);
std::vector<ip_adress> ipfilter(const std::vector<ip_adress> &ipv, int number1);
std::vector<ip_adress> ipfilter(const std::vector<ip_adress> &ipv, int number1, int number2);
std::vector<ip_adress> ipfilter_any(const std::vector<ip_adress> &ipv, int number1);

#endif // LIB201516072019_H
