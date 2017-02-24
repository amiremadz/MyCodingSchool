//============================================================================
// Name        : test.cpp
// Author      : Amir
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Cat.h"
#include "Person.h"
#include <sstream>

int main() {
	cout << "!!!Hello World!!!" << endl;
	cout << sizeof(long double) << endl;
	cout << sizeof(long int) << endl;

	Cat jim;
	//jim.makeHappy();
	jim.speak();
	jim.makeSad();
	jim.speak();

	{
		Cat tom;
		tom.speak();
	}

	Person person;

	cout << person.getName() << endl;
	person.setName("Ali");
	cout << person.getName() << endl;
	person.toString();
	person.setAge(18);
	person.toString();

	Person person2("Amir");
	person2.toString();

	Person person3("Sue", 24);
	cout << &person3 << endl;
	person3.toString();



	cout << "End of the program" << endl;
	return 0;
}
