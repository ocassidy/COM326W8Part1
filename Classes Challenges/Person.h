#pragma once

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class Person
{
private:
	std::string name_;
	std::string email_;
	std::string idNum_;

public:
	Person();
	Person(std::string name);
	Person(std::string name, std::string email, std::string idNum);

	~Person();

	void SetName(std::string name);
	std::string GetName() const;

	void SetEmail(std::string email);
	std::string GetEmail() const;

	void SetIDNum(std::string idNum);
	std::string GetID() const;

	virtual std::string ToString();
};


