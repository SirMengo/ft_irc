#include "client.hpp"

Client::Client() : _fd(-1), _realname(""), _nickname(""),
			_username(""), _hostname(""), _passwordOk(false),
			_registered(false), _validatedClient(false),
			_inputBuffer(""), _outputBuffer("")
{
}

Client::Client(int fd) : _fd(fd), _realname(""), _nickname(""),
			_username(""), _hostname(""), _passwordOk(false),
			_registered(false), _validatedClient(false),
			_inputBuffer(""), _outputBuffer("")
{
}

Client::~Client()
{}

void	Client::setRealname(std::string)
{
	
}

/* Fixed::Fixed()
{
	setRawBits(0);
	std::cout << "Default constructor called" << std::endl; 
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl; 
	*this = other;
}

Fixed	&Fixed::operator=(const Fixed &other)
{
	if (this == &other)
		return (*this);
	std::cout << "Copy assignment operator called" << std::endl;
	_value = other.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
} */

