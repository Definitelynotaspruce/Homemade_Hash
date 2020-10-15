#include "include/include.h"

std::string GetInput()
{
    std::string input;
    std::cout << "Input the data you want to hashify " << std::endl;
    std::cin >> input;
    return input;
}

std::string ReadInput(std::string fileName)
{
    std::ifstream data(fileName);
    if(data.fail()) 
        {
            std::cerr << "ERROR. Unable to open input file" << fileName  << std::endl;
            std::exit(0);
        }
    std::string input;

    std::stringstream ss;
    ss << data.rdbuf();         //read the file
    std::string str = ss.str(); //str holds the content of the file

    data.close();

    return str;
}

