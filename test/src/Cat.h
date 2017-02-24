/*
 * Cat.h
 *
 *  Created on: Feb 20, 2017
 *      Author: amire
 */

#ifndef CAT_H_
#define CAT_H_

#include <iostream>
using namespace std;

class Cat{
	private:
		bool happy;
	public:
		Cat();
		~Cat();
		void makeHappy();
		void makeSad();
		void speak();
};




#endif /* CAT_H_ */
