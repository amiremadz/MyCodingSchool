#include <vector>
#include <iostream>

using namespace std;


int binsearch(vector<int> arr, int left, int right, int key, int first){
	int result = -1;
	while(left <= right){
		int mid = (left + right)/2;
		if(arr[mid] == key){
			result = mid;
			if(first){
				right = mid-1;
			}
			else{
				left = mid+1;
			}
		}
		if(arr[mid] > key){
			right = mid-1;
		}
		if(arr[mid] < key){
			left = mid+1;
		}
	}
	return result;
}

int find_first(vector<int> arr, int key){
	return binsearch(arr, 0, arr.size(), key, 1);
}

int find_last(vector<int> arr, int key){
	return binsearch(arr, 0, arr.size(), key, 0);
}


int count_occurances(vector<int> arr, int key){
	int first = find_first(arr, key);
	if(first == -1)
		return -1;
	int last = find_last(arr, key);
	if(last == -1)
		return -1;
	return (last - first + 1);

}

int count_rotations_linear(vector<int> arr){
	int min = 0;
	int n = static_cast<int>(arr.size());
	for(int i = 1; i < n; i++){
		if(arr[i] < arr[min])
			min = i;
	}
	return min;
}

int count_rotations_log(vector<int> arr){
	int left = 0;
	int right = arr.size()-1;
	int n = arr.size();

	if(arr[left] < arr[right])
		return 0;

	while(left <= right){
		if(arr[left] <= arr[right])
			return left;
		int mid = (left + right)/2;
		int next = (mid + 1)%n;
		int prev = (mid + n - 1)%n;
		if(arr[mid] < next && arr[mid] < prev)
			return mid;
		else if(arr[left] <= arr[mid]){
			left = mid + 1;
		}
		else if (arr[mid] <= arr[right]){
			right = mid - 1;
		}
	}
	return -1;

}


int find_element_rotated_arr(vector<int> arr, int key){
	int low = 0;
	int high = arr.size() - 1;
	while(low <= high){
		int mid = (low + high)/2;
		if(arr[mid] == key)
			return mid;
		else if(arr[low] <= arr[mid]){
			if(key < arr[mid] && key >= arr[low])
				high = mid - 1;
			else
				low = mid + 1;
		}
		else if(arr[mid] <= arr[high]){
			if(key > arr[mid] && key <= arr[high])
				low = mid + 1;
			else
				high = mid - 1;
		}
	}
	return -1;
}


int main(){

	vector<int> arr = {1, 2, 3,  3, 3, 3, 3, 3, 4, 7, 8, 8, 8, 9};
	vector<int> rotated_arr = {3, 5, 8, 11, 12, 2};

	cout << find_first(arr, 3) << endl;
	cout << find_first(arr, 8) << endl;

	cout << find_last(arr, 3) << endl;
	cout << find_last(arr, 8) << endl;

	cout << count_occurances(arr, 3) << endl;

	cout << count_rotations_linear(rotated_arr) << endl;

	cout << count_rotations_log(rotated_arr) << endl;

	cout << find_element_rotated_arr(rotated_arr, 8);


	return 0;
}
