# include "conversor.hpp"

Conversor::Conversor()
:
	_int(0),
    _float(0),
    _char(0),
    _double(0),
    _src("")
{}

Conversor::Conversor(std::string const &src)
:
	_int(0),
    _float(0),
    _char(0),
    _double(0),
    _src(_src)
{}

Conversor::Conversor(Conversor const &copy)
:
	_int(copy._int),
    _float(copy._float),
    _char(copy._char),
    _double(copy._double),
    _src(copy._src)
{}

Conversor::~Conversor(){}

Conversor &Conversor::operator=(Conversor const &op)
{
	this->_int = op._int;
    this->_float = op._float;
    this->_char = op._char;
    this->_double = op._double;
    this->_src = op._src;
	return (*this);
}

// Getter - Setter
int Conversor::getInt() const {return(this->_int);} 
float Conversor::getFloat() const {return(this->_float);} 
char Conversor::getChar() const {return(this->_char);} 
double Conversor::getDouble() const {return(this->_double);} 
std::string Conversor::getSrc() const {return(this->_src);} 

//exceptions
const char* Conversor::SomeException::what() const throw()
{
	return "Exception: ";
}