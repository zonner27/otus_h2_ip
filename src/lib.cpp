#include "lib.h"


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

ip_adress ipget(const std::vector<std::string> &strv)
{
    return std::make_tuple(std::stoi(strv[0]), std::stoi(strv[1]), std::stoi(strv[2]), std::stoi(strv[3]));
}

void print2(const std::vector<ip_adress> &ipv)
{
    for (unsigned int i = 0; i < ipv.size(); i++)
        std::cout << static_cast<int>(std::get<0>(ipv[i])) << "."
                  << static_cast<int>(std::get<1>(ipv[i])) << "."
                  << static_cast<int>(std::get<2>(ipv[i])) << "."
                  << static_cast<int>(std::get<3>(ipv[i])) << std::endl;
}

std::vector<ip_adress> ipfilter(const std::vector<ip_adress> &ipv, int number1)
{
    std::vector<ip_adress> filter;
    for (unsigned int i = 0; i < ipv.size(); i++)
        if (std::get<0>(ipv[i]) == number1)
            filter.push_back(ipv[i]);
    return filter;
}

std::vector<ip_adress> ipfilter(const std::vector<ip_adress> &ipv, int number1, int number2)
{
    std::vector<ip_adress> filter;
    for (unsigned int i = 0; i < ipv.size(); i++)
        if ((std::get<0>(ipv[i]) == number1) && (std::get<1>(ipv[i]) == number2))
                filter.push_back(ipv[i]);
    return filter;
}

std::vector<ip_adress> ipfilter_any(const std::vector<ip_adress> &ipv, int number1)
{
    std::vector<ip_adress> filter;
    for (unsigned int i = 0; i < ipv.size(); i++)
        if ((std::get<0>(ipv[i]) == number1) || (std::get<1>(ipv[i]) == number1) || (std::get<2>(ipv[i]) == number1) || (std::get<3>(ipv[i]) == number1))
                filter.push_back(ipv[i]);
    return filter;
}
