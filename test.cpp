#include <iostream>
#include <fstream>
#include <chrono>
#include <sstream>

#include "include/include.h"
#include "include/homemade_hash.h"

void speed(std::string filename)
{   
    std::string input = ReadInput(filename);
    std::cout << "\n SPEED TEST" << std::endl;
    std::string line("");
    std::bitset<128> hash;

    std::stringstream ss(input);
    auto start = std::chrono::system_clock::now();
    while (std::getline(ss, line))
        hash = HomemadeHash(input);        
    
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "Hash was working for " << (elapsed_seconds.count())/789 << " seconds" << std::endl
    << "END OF SPEED TEST \n" << std::endl;
}

int main()
{   
    std::vector<std::string> filename = 
    {   "textFiles/konstitucija.txt", "textFiles/emptyFile.txt", 
        "textFiles/oneSimbol1.txt", "textFiles/oneSimbol2.txt"  };
    
    speed(filename[0]);
    //colision();
        

    return 0;
}