#ifndef HOMEMADE_HASH_H
#define HOMEMADE_HASH_H

#include <iostream>
#include <string>
#include <iomanip>
#include <bitset>
#include <vector>

std::bitset<128> HomemadeHash(const std::string&);
std::bitset<4> *getBitset4(std::bitset<128>);

template <size_t N1, size_t N2 >
std::bitset <N1 + N2> concat( const std::bitset <N1> & b1, const std::bitset <N2> & b2 ) {
    std::string s1 = b1.to_string();
    std::string s2 = b2.to_string();
    return std::bitset <N1 + N2>( s1 + s2 );
}

#endif