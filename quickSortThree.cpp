#include <iostream>
#include <array>
using namespace std;


template <class T>
void printArray( T a[] ); //This is a prototype

/* This implementation of quicksort is based on the answer for problem 3.4.5 
it has been modified so that only a single pass of the array is performed by the partitioning algorithm. */
template <class T>
void partition(T a[], int start, int stop, int & pivot){

	int p = start;
	int q = start;
	int r = stop-1;
	swap(a[pivot], a[r]);
	T myPivot = a[r];
	while(q < r){
		if(a[q] <= myPivot){
			swap(a[p], a[q]);
			++p;
		}
		++q;
	}
	swap(a[p], a[r]);
	pivot = p;
}

template <class T>
void quicksort(T a[], int start, int stop)
{
	if (stop - start > 1) {
		int pivot = start + rand() % (stop - start);
//		int pivot = start;
		
		partition(a, start, stop, pivot);
		quicksort(a, start, pivot);
		quicksort(a, pivot + 1, stop);
	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

template <class T>
void printArray(T a[]){
	for(int i = 0; i < 5; i++){
		cout << a[i] << " ";
	}
	cout<<'\n';
}

//A simple little test driver! Let's prove that our implementation is functional.
int main(){
	int nums[5] = {5, 4, 2, 3, 1};
	char lets[5] = {'d', 'c', 'e', 'b', 'a'};
	
	quicksort(nums, 0, 5);
	quicksort(lets, 0, 5);
	
	printArray(nums);
	printArray(lets);
	
	return 0;
}
