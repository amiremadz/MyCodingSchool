/*
 * mymain.cpp
 *
 *  Created on: Dec 29, 2016
 *      Author: amire
 */
#include <iostream>
#include <vector>
#include <climits>
using namespace std;


void print(vector<int> &arr){
	for(int item:arr)
		cout << item << " ";
	cout << endl;
}

int find_sum(vector<int> &arr, const int beg, const int end){
	int sum = 0;
	for(int i=beg; i<=end; i++)
		sum += arr[i];
	return sum;
}

int maxsumsubarray_bruteforce_n3(vector<int> &arr){
	int mss = INT_MIN;
	int N = arr.size();

	for(int length=1; length<=N; length++){
		for(int beg=0; beg+length-1<N; beg++){
			int end = beg+length-1;
			int sum = find_sum(arr, beg, end);
			if(sum > mss)
				mss = sum;
		}
	}
	return mss;
}

int maxsumsubarray_bruteforce_n2(vector<int> &arr){
	int mss = INT_MIN;
	int N = arr.size();
	for(int beg=0; beg<N; beg++){
		int sum = 0;
		for(int j=beg; j<N; j++){
			sum += arr[j];
			if(sum > mss)
				mss = sum;
		}
	}
	return mss;
}

int find_maxleftsum(vector<int> arr, int left, int right){
	int result = INT_MIN;
	int sum = 0;
	for(int i=right; i>=left; i--){
		sum += arr[i];
		if(sum > result)
			result = sum;
	}
	return result;
}

int find_maxrightsum(vector<int> arr, int left, int right){
	int result = INT_MIN;
	int sum = 0;
	for(int i=left; i<=right; i++){
		sum += arr[i];
		if(sum > result)
			result = sum;
	}
	return result;
}


int maxsumsub(vector<int> arr, int left, int right){
	if(left == right)
		return arr[left];
	int mid = (left + right)/2;
	int mss_left = maxsumsub(arr, left, mid);
	int mss_right = maxsumsub(arr, mid+1, right);
	int leftsum = find_maxleftsum(arr, left, mid);
	int rightsum = find_maxrightsum(arr, mid+1, right);
	int tot = leftsum + rightsum;
	int result = mss_left;
	if(mss_right > result)
		result = mss_right;
	if(tot > result)
		result = tot;
	return result;
}

int maxsumsub(vector<int> arr){
	return maxsumsub(arr, 0, arr.size());
}


int kadane(vector<int> arr){
	int sum = 0;
	int mss = 0;
	for(int item:arr){
		sum += item;
		if(sum > 0){
			if(sum > mss)
				mss = sum;
		}
		else{
			sum = 0;
		}
	}
	return mss;
}


int main(){
	int mss;
	//vector<int> arr = {3, -2, 5, -1, 8, -4};
	vector<int> arr = {1, -3, 2, -5, 7, 6, -1, -4, 11, -23};
	print(arr);
	mss = maxsumsubarray_bruteforce_n3(arr);
	cout << "Brute force n3: " << mss << endl;
	mss = maxsumsubarray_bruteforce_n2(arr);
	cout << "Brute force n2: " << mss << endl;
	mss = maxsumsub(arr);
	cout << "Recursive: " << mss << endl;
	mss = kadane(arr);
	cout << "Kadane: " << mss << endl;

	return 0;
}





