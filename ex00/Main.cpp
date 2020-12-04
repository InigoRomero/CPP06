# include <iostream>
# include <string>
# include "Conversor.hpp"

int failed()
{
    std::cout << "wow something goes wrong. Exiting..." << std::endl;
    return (-1);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
        return (failed());
    Conversor vars = Conversor(argv[1]);
    std::cout << vars << std::endl;
    return (0);
}