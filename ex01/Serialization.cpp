# include "Serialization.hpp"

void *serialize(void)
{
    char *raw = new char[20];
	static std::string alphabet = "0123456789" \
		"abcdefghijklmopqrstuvxyz" \
		"ABCDEFGHIJKLMOPQRSTUVXYZ";
    
    for (int i = 0; i < 8; i++)
		raw[i] = alphabet[rand() % alphabet.length()];
	*reinterpret_cast<int*>(raw + 8) = rand() % 424242;
	for (int i = 0; i < 8; i++)
		raw[i + 12] = alphabet[rand() % alphabet.length()];
	return (raw);
}

Data *deserialize(void *raw)
{
	Data *d = new Data;

	d->s1 = std::string(static_cast<char*>(raw), 8);
	d->n = *reinterpret_cast<int*>(static_cast<char*>(raw) + 8);
	d->s2 = std::string(static_cast<char*>(raw) + 12, 8);
	return (d);
}