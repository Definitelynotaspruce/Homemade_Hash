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

void compare(std::string filename)
{
    std::string data = ReadInput("textFiles/twoLines.txt");
    
    std::stringstream ss(data);
    std::string line1(""), line2("");
    int bitsOnLine = 0;
    int totalBits = 0;

    std::cout << "---\nComparison started---" << std::endl;
    while (std::getline(ss, line1)) 
    {   
        std::getline(ss, line2);
        totalBits =+ compareOnBit (HomemadeHash(line1), HomemadeHash(line2));
    }
    std::cout << "---Comparison ended---" << std::endl;

}

int main()
{   
    std::vector<std::string> filename = 
    {   "textFiles/konstitucija.txt", "textFiles/emptyFile.txt", 
        "textFiles/oneSimbol1.txt", "textFiles/oneSimbol2.txt",
        "textFiles/1mil_2.txt", "textFiles/1mil.txt" };
    
    speed(filename[0]);
    collision(filename[0]);
    compare(filename[5]);
        

    return 0;
}