# include "Conversor.hpp"

Conversor::Conversor()
:
	_int(0),
    _float(0),
    _char(0),
    _double(0),
    _src()
{}

Conversor::Conversor(char *src)
:
	_int(0),
    _float(0),
    _char(0),
    _src(src)
{
    std::string nan = "nan";
    if (isdigit(src[0]))
    {
        try
        {
            this->_double = atof(new char[nan.length() + 1]);
        }
        catch (std::invalid_argument) {
            this->_double = atof("nan");
            this->_src = new char[nan.length() + 1];
        }
        toAll();
    }
    else
        this->_char = src[0];
}

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

std::ostream    &operator<<(std::ostream & out, const Conversor & Conversor)
{
    //char
    if (!strcmp(Conversor.getSrc(), "nan"))
        out << "[+]char: impossible";
    else if(Conversor.getChar() <= 32)
        out << "[+]char: Non displayable";
    else
        out << "[+]char: '" << Conversor.getChar() << "'";
    //int
    if (!strcmp(Conversor.getSrc(), "nan"))
        out << "\n[+]int: impossible";
    else
        out << "\n[+]int: " << Conversor.getInt();
    //float
    if (Conversor.getFloat() == Conversor.getInt())
        out << "\n[+]Float: " << Conversor.getFloat() << ".0f";
    else
        out << "\n[+]float: " << Conversor.getFloat()  << "f";
    //double
    if (Conversor.getDouble() == Conversor.getInt())
        out << "\n[+]Double: " << Conversor.getDouble() << ".0";
    else
        out << "\n[+]Double: " << Conversor.getDouble();
    return (out);
}

//conversions En general, se usa static_cast cuando se desea convertir tipos de datos numéricos, como las enumeraciones, a ints o ints en valores Float...
//https://docs.microsoft.com/es-es/cpp/cpp/static-cast-operator?view=msvc-160
void Conversor::toInt()
{
    this->_int = static_cast<int>(this->_double);
} 
void Conversor::toFloat()  
{
    this->_float = static_cast<float>(this->_double);
} 
void Conversor::toChar()  
{
     this->_char = static_cast<char>(this->_double);
} 

void Conversor::toAll()  
{
    toInt();
    toFloat();
    toChar();
} 

// Getter - Setter
int Conversor::getInt() const {return(this->_int);} 
float Conversor::getFloat() const {return(this->_float);} 
char Conversor::getChar() const {return(this->_char);} 
double Conversor::getDouble() const {return(this->_double);} 
char* Conversor::getSrc() const {return(this->_src);} 

//exceptions
const char* Conversor::SomeException::what() const throw()
{
	return "Exception: ";
}