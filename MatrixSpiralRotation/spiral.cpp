/*
 * spiral.cpp
 *
 *  Created on: Nov 30, 2016
 *      Author: shiva
 */
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;


void print(vector< vector<int> > arr){
	int n = arr.size();
	int m = arr[0].size();
	int width = 4;
	for(int i=0; i< m; i++)
	{
		for(int j=0; j<n; j++)
			cout << setw(width) << arr[i][j];
		cout << endl;
	}
}

void spiral(vector< vector<int> > &arr){
	int m = arr.size();
	int n = arr[0].size();
	int dir = 0;
	int up = 0;
	int down = m-1;
	int left = 0;
	int right = n-1;

	while(left <= right && up <= down){
		switch(dir){
		case 0:
			for(int i=left; i<=right; i++)
				cout << setw(4) << arr[up][i];
			up++;
			break;
		case 1:
			for(int i=up; i<=down; i++)
				cout << setw(4) << arr[i][right];
			right--;
			break;
		case 2:
			for(int i=right; i>=left; i--)
				cout << setw(4) << arr[down][i];
			down--;
			break;
		case 3:
			for(int i=down; i>=up; i--)
				cout << setw(4) << arr[i][left];
			left++;
			break;
		}
		dir = (dir+1)%4;
	}

}

int main(){

	int n = 5;
	int k = 0;
	vector< vector<int> > arr(n, vector<int>(n));
	for(int i = 0; i<n; i++)
		for(int j=0; j<n; j++)
		{
			arr[i][j] = k;
			k++;
		}

	print(arr);
	spiral(arr);

	return 0;
}



