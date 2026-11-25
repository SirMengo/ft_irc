#ifndef CLIENT_HPP
# define CLIENT_HPP

# include <iostream>
# include <string>

# define BLUE "\033[1;34m"
# define WHITE "\033[0m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"

class Client
{
	public:
		Client();
		Client(int fd);
		~Client();
		void	Client::setRealname(std::string);
	

	private:
		int				_fd;
		std::string		_realname;
		std::string		_nickname;
		std::string		_username;
		std::string		_hostname;
		bool			_passwordOk;
		bool			_registered;
		bool			_validatedClient;
		std::string		_inputBuffer;
		std::string		_outputBuffer;
};

#endif