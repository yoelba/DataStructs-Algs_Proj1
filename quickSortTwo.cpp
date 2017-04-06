#include <iostream>
#include <array>
using namespace std;


template <class T>
void printArray( T a[] ); //This is a prototype

/* This implementation of quicksort is based on the answer for problem 3.4.5 
it has been modified so that only a single pass of the array is performed by the partitioning algorithm. */
template <class T>
void partition(T a[], int start, int stop, int & pivot){
/*
	THIS WORKS! ASPIRE TO SIMILARITY
	
	T * temp = new T[stop - start];
	int k = 0; // next available position in temp
	for (int i = start + 1; i < stop; ++i)
		if (a[i] < a[start]) {
			temp[k] = a[i];
			++k;
	}
	temp[k] = a[start]; // pivot
	pivot = start + k; // final index in a.
	++k;
	
	for (int i = start + 1; i < stop; ++i)
		if (!(a[i] < a[start])){
			temp[k] = a[i];
			++k;
	}
	
	copy(temp, temp + k, a + start);
	delete temp;
*/
	T * temp = new T[stop - start];
	int k = 0;
	int bk = 0; // Stands for 'back k', not 'Burger King'
	for(int i = start+1; i < stop; ++i){
		if(a[i] < a[start]){
			temp[k] = a[i];
			++k;
			cout << " 'If' triggered :- " << a[i] << '\n';
		}else{	
	//		temp[k + 2 + bk] = a[i];
			temp[ ((stop-start)-1) - (bk) ] = a[i];
			cout << " 'Else' triggered :- " << a[i] << " sent to " << ( (stop-start) - (bk) ) << '\n';
			++bk;
		}
	}
	temp[k] = a[start];
	pivot = start+k;
	++k;
	k += bk;

	copy(temp, temp + k, a + start);
	delete temp;
	cout << "We're sorting an array. Currently :";  //debug
	printArray(a); //debug
	cout << "	Partitioned from " << start << " to " << stop <<" With pivot = " << a[pivot] << " at position " << pivot << "\n"; //debug
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
