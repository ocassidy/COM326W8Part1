#pragma once

#include "Module.h"
#include "Person.h"

class Lecturer : public Person {
private:
	std::string course_;
	std::vector<Module> modulesTaught_{};

public:
	//Public member functions

	//Our default constructor. This does nothing other than create an empty student object. 
	//There isn't any data in the student object
	Lecturer();

	//Custom constructor. We use this to initialise the object with data we pass in
	Lecturer(std::string name);
	Lecturer(std::string name, std::string course, std::string idNum, std::string email);

	//Student class destructor
	~Lecturer();

	void SetCourse(std::string course);
	std::string GetCourse() const;

	void SetModules(std::vector<Module> modulesTaught);
	std::vector<Module> GetModules() const;

	virtual std::string ToString() override;
};
