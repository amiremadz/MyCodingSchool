/*
 * Cat.cpp
 *
 *  Created on: Feb 20, 2017
 *      Author: amire
 */
#include "Cat.h"


Cat::Cat(){
	happy = true;
}

Cat::~Cat(){
	cout << "Cat destroyed." << endl;
}

void Cat::makeHappy(){
	happy = true;
}

void Cat::makeSad(){
	happy = false;
}

void Cat::speak(){
	if(happy){
		cout << "Meouuw!" << endl;
	}
	else{
		cout << "Sssss!" << endl;
	}
}
