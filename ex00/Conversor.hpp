
#ifndef CONVERSOR_HPP
# define CONVERSOR_HPP

# include <string>
# include <fstream>
# include <math.h>
# include <iostream>

class Conversor
{
	private:
		int _int;
        float _float;
        char _char;
        double _double;
        char *_src;

	public:
        Conversor();
		Conversor(char *src);
		Conversor(Conversor const &copy);
		virtual ~Conversor();
		Conversor &operator=(Conversor const &op);

        //getter - setter
        int          getInt() const;
        float        getFloat() const;
        char         getChar() const;
        double       getDouble() const;
        char*  getSrc() const;

        //conversions
        void         toInt();
        void         toFloat();
        void         toChar();
        void         toAll();

        //exceptions
        class SomeException: public std::exception {
		    virtual const char* what() const throw();
	    };
};

std::ostream    &operator<<(std::ostream & out, const Conversor & Conversor);

#endif