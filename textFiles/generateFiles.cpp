#include <string>
#include <random>
#include<fstream>

std::string random_string(std::size_t length)
{
    const std::string CHARACTERS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghi^&*()_+}{:><|~`";

    std::string random_string;

    for (std::size_t i = 0; i < length; ++i)
    {
        random_string += CHARACTERS[rand() % (CHARACTERS.length() - 1)]; 
    }

    return random_string;
}

int main()
{
    int stringNum = 2500;
    int lineNum = 1000;
    int changeNum = 999;
    std::ofstream output( std::to_string(stringNum) + "_" + std::to_string(lineNum) + "_" + std::to_string(changeNum) + ".txt");

    const std::string CHARACTERS = "jklmnopqrstuvwxyz!@#$%";

    
    std::string stringLine = " ";
       
    while (stringNum > 0)
    {
        stringLine = random_string(lineNum);
        output << stringLine << std::endl;
        stringLine[changeNum] = CHARACTERS[rand() % (CHARACTERS.length() - 1)]; 
        output << stringLine << std::endl;
        stringNum -=2;
    }
    output.close();

    return 0;
}