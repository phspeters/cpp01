#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
public:
	Contact();
	~Contact();
	
	void		setContactInfo();
	void		displayContactInfo();

	std::string	getFirstName();
	std::string	getLastName();
	std::string	getNickname();

private:
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;
};

std::string truncateString(const std::string& str);

#endif