#include "include/include.h"
#include "include/homemade_hash.h"

int main(int argc, char *argv[])
{
    std::string input;
     
     if (argv[1] == "a" ) std::cout << "hey" << std::endl;

    switch (argc)
    {
    case 1:
        input = GetInput();
        break;
    case 2:
        input = ReadInput(argv[1]);
        break;
    default:
        std::cerr << " Error. No input file. ";
    }
    
    std::cout << getBitset4(HomemadeHash(input));
    return 0;
}