/*
 * Person.h
 *
 *  Created on: Feb 20, 2017
 *      Author: amire
 */

#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>
#include <sstream>

using namespace std;

class Person{
	private:
		string name;
		int age;
	public:
		Person();
		Person(string newName){name = newName; age=0;};
		//Person(string name, int age): name(name), age(age){};
		Person(string name, int age);
		void setName(string newName);
		string getName();
		void setAge(int newAge);
		int getAge();
		void toString();
};


#endif /* PERSON_H_ */
