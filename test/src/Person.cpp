/*
 * Person.cpp
 *
 *  Created on: Feb 20, 2017
 *      Author: amire
 */
#include "Person.h"

Person::Person(){
	name = "Undefined";
	age = 0;
}

Person::Person(string name, int age){
	this->name = name;
	this->age = age;
	cout << "Memory location of object: " << this << endl;
}


void Person::setName(string newName){
	name = newName;
}

string Person::getName(){
	return name;
}

void Person::toString(){
	stringstream ss;
	ss << "Name: ";
	ss << name;
	ss << "; age: ";
	ss << age;

	string info = ss.str();
	cout << info << endl;
}

void Person::setAge(int newAge){
	age = newAge;
}
int Person::getAge(){
	return age;
}
