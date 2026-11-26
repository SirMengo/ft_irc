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

		// ? Set Functions
		void	setRealname(const std::string& realname);
		void	setNickname(const std::string& nickname);
		void	setUsername(const std::string& username);
		void	setHostname(const std::string& hostname);
		void	setPasswordOk();
		void	setRegistered();
		void	setValidatedClient();

		// * Get Functions
		int		getFd() const;
		const std::string	getRealname() const;
		const std::string	getNickname() const;
		const std::string	getUsername() const;
		const std::string	getHostname() const;
		bool	getPasswordOk();
		bool	getRegistered();
		bool	getValidatedClient();

		// ! Buffers Functions
		void	setInputBuffer(const std::string& data);
		const std::string	getInputBuffer();
		void	clearBuffer();
		void    appendToInput(const std::string& data);

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