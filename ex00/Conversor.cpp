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
    _double(0)
{
    std::string nan = "nan";
    if (!strcmp(src, "nanf"))
    {
        src = new char[nan.length() + 1];
        strcpy(src, "nan");
    }
    if (isdigit(src[0]) || !strcmp(src, "nan") || !strcmp(src, "NaN") || src[0] == '-' || src[0] == '+' || !strcmp(src, "inf") || !strcmp(src, "inff"))
    {
        try
        {
             this->_double = atof(src);
        }
        catch (std::invalid_argument) {
            this->_double = atof("nan");
            this->_src = new char[nan.length() + 1];
            strcpy(this->_src, "nan");
        }
        toAll();
    }
    else
        this->_char = src[0];
    for (int i=0; i<(int)strlen(src); i++)
        src[i] = tolower(src[i]);
    this->_src = src;
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
    char *src = Conversor.getSrc();
    if (!strcmp(src, "inff") ||!strcmp(src, "-inff") || !strcmp(src, "+inff") || !strcmp(src, "inf") ||!strcmp(src, "-inf") || !strcmp(src, "+inf"))
    {
        src = new char[4];
        strcpy(src, "nan");
    }
    if (Conversor.getInt() ==  -2147483648 &&  strcmp(src, "-2147483648") && strcmp(src, "nan"))
    {
        src = new char[11];
        strcpy(src, "impossible");
    }
    if (!strcmp(src, "nan") || !strcmp(src, "impossible") || Conversor.getInt() > 127 || Conversor.getInt() < 0)
        out << "[+]char: impossible";
    else if(Conversor.getChar() <= 32)
        out << "[+]char: Non displayable";
    else
        out << "[+]char: '" << Conversor.getChar() << "'";
    //int
    if (!strcmp(src, "nan"))
        out << "\n[+]int: impossible";
    else if (!strcmp(src, "impossible"))
        out << "\n[+]int: impossible";
    else
        out << "\n[+]int: " << Conversor.getInt();
    //float
    if (Conversor.getFloat() == Conversor.getInt())
        out << "\n[+]Float: " << Conversor.getFloat() << ".0f";
    else if (!strcmp(src, "impossible"))
        out << "\n[+]float: impossible";
    else
        out << "\n[+]float: " << Conversor.getFloat()  << "f";
    //double
    if (Conversor.getDouble() == Conversor.getInt())
        out << "\n[+]Double: " << Conversor.getDouble() << ".0";
    else if (!strcmp(src, "impossible"))
        out << "\n[+]Double: impossible";
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