#include <string>
#include <sstream>
#include "Person.h"

Person::Person(){
}

Person::Person(std::string name){
}

Person::Person(std::string name, std::string email, std::string idNum){
}

Person::~Person(){
}

void Person::SetName(std::string name){
	name_ = name;
}

std::string Person::GetName() const {
	return name_;
}

void Person::SetEmail(std::string email){
	email_ = email;
}

std::string Person::GetEmail() const{
	return email_;
}

void Person::SetIDNum(std::string idNum){
	idNum_ = idNum;
}

std::string Person::GetID() const
{
	return idNum_;
}

std::string Person::ToString() {
	std::ostringstream output;
	std::cout << "Details of the base person object are: " << std::endl;
	output << "Base person details " << GetName() << ", " << GetEmail() << GetID() << std::endl;

	return output.str();
}