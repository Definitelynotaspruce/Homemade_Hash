#include <iostream>
#include <fstream>
#include <chrono>
#include <sstream>
#include <unordered_set>

#include "include/include.h"
#include "include/homemade_hash.h"

void speed(std::string filename)
{   

    std::string input = ReadInput(filename);
    std::cout << "\n---SPEED TEST---" << std::endl;
    std::string line("");

    std::stringstream ss(input);
    auto start = std::chrono::system_clock::now();
    while (std::getline(ss, line))
        HomemadeHash(line); 
        
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "Hash was working for " << (elapsed_seconds.count())<< " seconds" << std::endl
    << "---END OF THE SPEED TEST---\n" << std::endl;
}

void collision(std::string filename)
{
    std::string data = ReadInput(filename);
    std::unordered_set<std::bitset<128>> seen_before;
    int collisions = 0, count = 0;
    auto hash = HomemadeHash(" ");
    
    std::stringstream ss(data);
    std::string line = " ";

    std::cout << "---Collision detection started---" << std::endl;
    while (std::getline(ss, line)) 
    {
        ++count;
        hash = HomemadeHash(line);
        auto i = seen_before.find(hash);
        if (i == seen_before.end()) 
        {
            seen_before.emplace_hint(i, hash);
        }
        else 
        {
            ++collisions;
        }
    }
    std::cout << "Total Input is " << count << std::endl;
    std::cout << "Collision # is " << collisions << std::endl;
    std::cout << "---Collision detection ended---" << std::endl;
}

int compareOnBit(std::bitset<128> hash1, std::bitset<128> hash2)
{
    int sameBit = 0;
    for (std::size_t i = 0; i < 128; ++i)
        if (hash1[i] == hash2[i])
            sameBit++;
    
    return sameBit;
}

int compareOnHex(std::string hash1, std::string hash2)
{
    int sameHex = 0;
    for (std::size_t i = 0; i < hash1.length(); ++i)
    {   
        if (hash1[i] == hash2[i])
           sameHex++;
    }       
    
    return sameHex;
}

void compare(std::string filename)
{
    std::string data = ReadInput(filename);
    
    std::stringstream ss(data);
    std::string line1(""), line2("");
    int bitsOnLine = 0;
    int totalBits = 0, totalHex = 0;
    int lineCount = 0;

    std::cout << "\n---Comparison started---" << std::endl;
    while (std::getline(ss, line1)) 
    {   
        std::getline(ss, line2);
        
        totalBits += compareOnBit (HomemadeHash(line1), HomemadeHash(line2));
        totalHex += compareOnHex (getBitset4(HomemadeHash(line1)), getBitset4(HomemadeHash(line2)));
        lineCount += 2;
    }

    std::cout << "The average difference between two imputs on a BIT level that have 1 simbol diff is " 
    << 100 - (double)totalBits/lineCount*100/128 << "%\n";  
    std::cout << "The average difference between two imputs on a HEX level that have 1 simbol diff is " 
    << 100 - (double)totalHex/lineCount*100/32 << "%\n";  
    
    std::cout << "---Comparison ended---" << std::endl;

}

int main()
{      
    speed("textFiles/konstitucija.txt");
    collision("textFiles/2500_1000_499.txt");
    compare("textFiles/2500_1000_499.txt");
        

    return 0;
}