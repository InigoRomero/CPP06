# include <iostream>
# include <string>


int failed()
{
    std::cout << "wow something goes wrong. Exiting..." << std::endl;
    return (-1);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
        return (failed());
    (void)argv[1];
    return (0);
}