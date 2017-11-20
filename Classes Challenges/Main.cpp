/*
* Main.cpp
*
* Version information v0.1
* Author: Dr. Shane Wilson
* Date: 8/10/2017
* Description: Driver to test the student class
* Copyright notice
*/

#include <iostream>
#include "Student.h"
#include "Module.h"

using namespace std;

int main() {

	Student stu1("Jeni Watt", "B004568656", "BSc Computing", 1);
	Student stu2("Frank Lyons");
	Student stu3{};

	//Overload the input operator
	//cin >> stu3;

	//Call the static member function
	cout << "The number of students enrolled is: " << Student::GetEnrolled() << endl;

	Module module { "Software testing for beginners", "TES101", 20, 80 };
	Module module2 { "Software testing for ninjas ", "BAK101", 20, 80 };
	stu1.AddModule(module);
	stu1.AddModule(module2);
	std::string result = stu1.CalculateClassification();

	//output student 1 details

	cout << "Student 1 details" << endl << endl;
	//cout << "Name: " << stu1.GetName() << "Registration: " << stu1.GetRegistrationID() << "Course: " << stu1.GetCourse() << "Year of study: " << stu1.GetYearofStudy() << endl << endl;
	cout << stu1;

	if (stu1 == stu2) {
		cout << "they are the same" << endl;
	}
	else {
		cout << "they are not the same" << endl;
	}

	stu1.DeleteModule("TES101");

	stu3.SetName("Paul Doherty");
	stu3.SetCourse("BSc Geology");
	stu3.SetRegistrationID("B004556565");
	stu3.SetYearofStudy(3);

	return 0;
}

