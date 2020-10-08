#include <iostream>
#include <string>
#include <iomanip>
#include <bitset>
#include <fstream>
#include <sstream>

std::string GetInput()
{
    std::string input;
    input = "1";
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

std::string HomemadeHash(const std::string &str)
{
    int primeB = 63689;
    int primeA = 21515;
    unsigned int hash = 0;
    std::string hexHash;

    while (hexHash.size() < 32 )
    {
        for (std::size_t i = 0; i < str.size(); ++i)
        {
            hash = hash * str.size() + int(str[i])*primeB;
            primeB = primeB * int(str[i]) + str[i];
        }
        hexHash = hexHash + int_to_hex(hash);
    }

    std::cout << "size of " << hexHash.size() << std::endl;

    return hexHash;
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
    std::cout << HomemadeHash(input) << std::endl;
    return 0;
}