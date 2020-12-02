# include "Serialization.hpp"

int main ()
{
    srand(time(NULL));

	void* raw = serialize();
	Data* data = deserialize(raw);
	
	std::cout << "[+] S1: " << data->s1 << std::endl;
	std::cout << "[+] N:" << data->n << std::endl;
 	std::cout << "[+] S2:" << data->s2 << std::endl;

    delete reinterpret_cast<char*>(raw);
	delete data;

    return (0);
}