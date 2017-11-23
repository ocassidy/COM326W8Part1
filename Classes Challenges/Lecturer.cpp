#include "Lecturer.h"

Lecturer::Lecturer(){
	std::cout << "Lecturer constructor called" << std::endl;
}

Lecturer::Lecturer(std::string name) : Person(name) {
	std::cout << "Lecturer name constructor called" << std::endl;
}

Lecturer::Lecturer(std::string name, std::string course, std::string idNum, std::string email) : Person(name, email, idNum), course_{ course } {
	std::cout << "Lecturer full constructor called" << std::endl;
}

Lecturer::~Lecturer(){
}

void Lecturer::SetCourse(std::string course){
	course_ = course;
}

std::string Lecturer::GetCourse() const{
	return course_;
}

void Lecturer::SetModules(std::vector<Module> modulesTaught){
	modulesTaught_ = modulesTaught;
}

std::vector<Module> Lecturer::GetModules() const{
	return modulesTaught_;
}

std::string Lecturer::ToString() {
	
	Module *modulesPtr{ nullptr };

	std::ostringstream output;
	std::cout << "Dervived lecturer details " << std::endl;
	output << Person::ToString() << GetCourse() << " ";

	for (unsigned int i = 0; i < modulesTaught_.size(); i++) {
		modulesPtr = &modulesTaught_[i];
		std::cout << modulesPtr;
	}
	
	delete modulesPtr;
	modulesPtr = nullptr;
	return output.str();
}