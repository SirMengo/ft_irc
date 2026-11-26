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

// ? Set Functions Names

void	Client::setRealname(const std::string& realname)
{
	_realname = realname;
}

void	Client::setNickname(const std::string& nickname)
{
	_nickname = nickname;
}

void	Client::setUsername(const std::string& username)
{
	_username = username;
}

void	Client::setHostname(const std::string& hostname)
{
	_hostname = hostname;
}

// ? Set Functions Bool

void	Client::setPasswordOk()
{
	_passwordOk = true;
}
void	Client::setRegistered()
{
	_registered = true;
}

void	Client::setValidatedClient()
{
	_validatedClient = true;
}

// * Get Functions

int		Client::getFd() const
{
	return (_fd);
}

const	std::string Client::getRealname() const
{
	return (_realname);
}

const	std::string Client::getNickname() const
{
	return (_nickname);
}

const	std::string	Client::getUsername() const
{
	return (_username);
}

const	std::string Client::getHostname() const
{
	return (_hostname);
}

bool	Client::getPasswordOk()
{
	return (_passwordOk);
}

bool	Client::getRegistered()
{
	return (_registered);
}

bool	Client::getValidatedClient()
{
	return (_validatedClient);
}

// ! Buffers Functions

void	Client::setInputBuffer(const std::string& data)
{
	_inputBuffer = data;
}

const std::string	Client::getInputBuffer()
{
	return (_inputBuffer);
}

void	Client::clearBuffer()
{
	_inputBuffer.clear();
}

void	Client::appendToInput(const std::string& data)
{
	_inputBuffer += data;
}