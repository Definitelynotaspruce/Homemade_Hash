#include <iostream>
#include <string>
#include <iomanip>
#include <bitset>
#include <fstream>
#include <sstream>
#include "include.h"

std::string GetInput()
{
    std::string input;
    input = "1gffffffgrtunurtbyyi jsrtg sjkrlj";
    return input;
}

std::string ReadInput(std::string fileName)
{
    std::ifstream data(fileName);
    std::string input;

    std::stringstream strStream;
    strStream << data.rdbuf();         //read the file
    std::string str = strStream.str(); //str holds the content of the file

    data.close();

    return str;
}

std::string TextToBinaryString(std::string input)
{
    std::string binaryString = "g";
    for (char &_char : input)
    {
        binaryString += std::bitset<8>(_char).to_string();
    }
    return binaryString;
}

std::string int_to_hex(int i)
{
    std::stringstream stream;
    stream << std::hex << i;
    return stream.str();
}

std::bitset<128> HomemadeHash(const std::string &str)
{
    
    unsigned int numA = 9933333;
    unsigned int numB = 1456;
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


int main(int argc, char *argv[])
{
    std::string input;
    switch (argc)
    {
    case 1:
        input = GetInput();
        break;
    case 2:
        input = ReadInput(argv[1]);
        break;
    default:
        std::cerr << " you failed ";
    }
    std::cout << (HomemadeHash(input)) << std::endl;
    return 0;
}