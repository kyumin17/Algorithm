#include <iostream>

using namespace std;

int arr*;

int bisectionSearch(int cube) {
	int start = 0;
	int end = sizeof(arr)/sizeof(int) - 1;
	int guess = (start + end)/2;
	
	while (arr[guess] != cube) {
		if (arr[guess] > cube)
			end = guess - 1;
		else
			start = guess + 1;
		guess = (start + end)/2;
	}
	
	return guess;
}
