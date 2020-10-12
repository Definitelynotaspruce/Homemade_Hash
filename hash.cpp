#include "include/homemade_hash.h"

std::bitset<4> *getBitset4(std::bitset<128> bit)
{
    std::string str = bit.to_string();
    std::vector<std::bitset<4>> bitVec;
    for (size_t i = 0; i <= str.size(); i += 4)
    {
        auto temp = str.substr(i, 4);
        bitVec.push_back(std::bitset<4>(temp));
    }

    for (auto &&i : bitVec)
    {
        std::cout << std::hex << i.to_ullong();
    }
    
    return 0;
}   


std::bitset<128> HomemadeHash(const std::string &str)
{
    
    unsigned int numA = 3131;
    unsigned int numB = 1373;
    unsigned int numC = 0;
    std::bitset<32> hash[4];

    for (std::size_t j = 0; j < sizeof(hash); ++j)
        {
            for (std::size_t i = 0; i < str.size(); ++i)
            {
                numB = numB * str.size() + int(str[i])*numA;
                numA = numA * int(str[i]) + str[i];
                numC = numA*numB;
            }
            hash[j] = std::bitset<32> (numC);
        }
    
    return concat(concat(hash[0],hash[2]), concat(hash[1],hash[3]));
}