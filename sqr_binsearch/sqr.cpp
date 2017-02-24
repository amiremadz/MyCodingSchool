/*
 * sqr.cpp
 *
 *  Created on: Dec 8, 2016
 *      Author: amire
 */

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

float eps = 1.0/(1LL<<15);

float mysqrt(float x){
	if(x >= 0){
		float left = 0;
		float right = x;
		if(x == 0 || x == 1)
			return x;
		if(x < 1.0)
			right = 1.0;
		while(left <= right){
			float mid = (left + right)/2.0;
			float error = mid*mid - x;
			if(abs(error) < eps)
				return mid;

			if(error < 0)
				left = mid;
			else if(error > 0)
				right = mid;
		}
	}
	return -1;

}

int main(){
	float x;
	x = .8;
	cout << fixed << setprecision(4) << mysqrt(x) << endl;
	x = 4;
	cout << fixed << setprecision(4) << mysqrt(x) << endl;
	x = 8.1;
	cout << fixed << setprecision(4) << mysqrt(x) << endl;
	x = .8;
	cout << fixed << setprecision(4) << mysqrt(x) << endl;
	x = .25;
	cout << fixed << setprecision(4) << mysqrt(x) << endl;
	x = 1.0;
	cout << fixed << setprecision(4) << mysqrt(x) << endl;
	x = 0.0;
	cout << fixed << setprecision(4) << mysqrt(x) << endl;
	return 0;
}


