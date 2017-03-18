#include <iostream>
#include <array>
using namespace std;

/* Here is EXTREMELY detailed pseudocode for the iterative implementation of insertion sort, courtesy of figure 3.10 of the course notes:

insertion_sort(a, i, j)
{
	for k = i+1 to j − 1
	// insert a[k] into a[i..k)
	x = a[k]
	p = k − 1
	while (p >= i and x < a[p])
		a[p+1] = a[p]
		−− p
	a[p+1] = x
}


REMEMBER:
 - generic
 - well documented
 - only uses the < comparator
*/

template <class T>
void insertion_sort(T a[], int i, int j){
	/* TBI: 
		>>> sweet documentation! 
		>>> Only use < comparator (Current implementation uses other comparators.) 
	*/
	
	for(int k = i+1; k <= (j-1); k++){
		//We must insert a[k] into ap[i... k]
		T x = a[k];
		int p = k-1;
		while ( p >= i && x < a[p] ){
			a[p+1] = a[p];
			--p;
		}
		a[p+1] = x;
	}
}

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
	
	insertion_sort(nums, 0, 5);
	insertion_sort(lets, 0, 5);
	
	printArray(nums);
	printArray(lets);
	
	return 0;
}
