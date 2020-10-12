#include <iostream>
#include <fstream>
#include <chrono>

#include "include/include.h"
#include "include/homemade_hash.h"

int main()
{   
    std::vector<std::string> filename = 
    {   "textFiles/konstitucija.txt", "textFiles/emptyFile.txt", 
        "textFiles/oneSimbol1.txt", "textFiles/oneSimbol2.txt"  };
    
    // hash speed test with konstitucija.txt file
    std::string input = ReadInput(filename[0]);

    auto start = std::chrono::system_clock::now();
    auto hash = HomemadeHash(input);
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << std::endl << "Hash was working for " << elapsed_seconds.count() << " seconds" << std::endl;  
    getBitset4(hash);

    return 0;
}