#include "include/include.h"

std::string GetInput()
{
    std::string input;
    input = "0";
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

