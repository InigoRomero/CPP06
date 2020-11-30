
#ifndef CONVERSOR_HPP
# define CONVERSOR_HPP

# include <string>
# include <fstream>

class Conversor
{
	private:
		int _int;
        float _float;
        char _char;
        double _double;
        std::string _src;

	public:
        Conversor();
		Conversor(std::string const &src);
		Conversor(Conversor const &copy);
		virtual ~Conversor();
		Conversor &operator=(Conversor const &op);

        //getter - setter
        int          getInt() const;
        float        getFloat() const;
        char         getChar() const;
        double       getDouble() const;
        std::string  getSrc() const;

        //conversions
        void         toInt();
        void         toFloat();
        void         toChar();
        void         toDouble();

        //exceptions
        class SomeException: public std::exception {
		    virtual const char* what() const throw();
	    };
};

#endif