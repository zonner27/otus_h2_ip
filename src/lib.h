#ifndef LIB_H
#define LIB_H

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>


void print(std::vector<std::vector<std::string>> ip_pool)
{
    for(std::vector<std::vector<std::string> >::const_iterator ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip)
    {
        for(std::vector<std::string>::const_iterator ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part)
        {
            if (ip_part != ip->cbegin())
            {
                std::cout << ".";

            }
            std::cout << *ip_part;
        }
        std::cout << std::endl;
    }
}

void print2(std::vector<std::string> strv)
{
    for (auto ip = strv.begin(); ip != strv.end(); ++ip)
    {
        if (ip != strv.begin())
            std::cout << ".";
        std::cout << *ip;
    }
    std::cout << std::endl;
}



std::vector<std::string> split(const std::string &str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}

bool ipcomparison(std::vector<std::string> str1, std::vector<std::string> str2)
{
    for (int i = 0; i < 4; i++)
    {
        if (std::stoi(str1[i]) > std::stoi(str2[i]))
            return true;
        else if (std::stoi(str1[i]) < std::stoi(str2[i]))
            return false;
    }
    return true;
}


bool ipfilter(std::vector<std::string> strv, std::string str)
{
    if (strv[0] == str)
        return true;
    else
        return false;
}

bool ipfilter(std::vector<std::string> strv, std::string str0, std::string str1)
{
    if (strv[0] == str0 && strv[1] == str1)
        return true;
    else
        return false;
}

bool ipfilter_any(std::vector<std::string> strv, std::string str)
{
    for (auto ip : strv)
    {
        if (ip == str)
        {
             return true;
             break;
        }
    }
    return false;
}


#endif // LIB_H
