#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

//-----------------------------------------------------

int Integer_count; // Global variable

// Class Integer
class Integer{
public:
        Integer() { int_value = 0; } // default constructor
        Integer( int x ) { int_value = x; } // constructor sets x
        Integer( const Integer & obj2 ); // copy other Integer, increment counter
        int value() const { return int_value; }
        bool operator<( const Integer & obj2 );
        void operator=( const Integer & obj2 );
	void operator=( const int x );
private:
       	int int_value;
};

inline Integer::Integer( const Integer & obj2 ){ // copy constructor
        Integer_count++;	
	int_value = obj2.value();
}

inline bool Integer::operator<( const Integer & obj2 ){
        Integer_count++;
        if(value() < obj2.value()) return true;
        else return false;
}

inline void Integer::operator=( const Integer & obj2 ){ 
        Integer_count++;
        int_value = obj2.value();
}

inline void Integer::operator=( const int x ){
	int_value = x;
}	

//-----------------------------------------------------

/* SELECTION SORT FROM SEC 3.1 */
template <class T>
void selection_sort(T a[], int start, int stop){

	while(stop - start > 1){
		auto itr_max = std::max_element(a + start, a + stop);
		std::swap(*itr_max, a[stop - 1]);
		--stop;
	}
}

/* MERGESORT FROM SEC 3.3 */
template <class T>
void mergesort(T a[], int start, int middle, int stop){

	T * result = new T[stop - start];
	int j = 0;
	while(start < middle && middle < stop){
		if(a[start] < a[middle]){
			result[j] = a[start];
			++start;	
		} else {
			result[j] = a[middle];
			++middle;
		}
		++j;
	}
	delete [] result;
}

/* INSERTION SORT STEP 1 */
template <class T>
void insertion_sort(T a[], int i, int j){
	
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

/* QUICKSORT STEP 2 */
template <class T>
void partition1(T a[], int start, int stop, int & pivot){

	T * temp = new T[stop - start];
	int k = 0;
	int bk = 0; // Stands for 'back k', not 'Burger King'
	for(int i = start+1; i < stop; ++i){
		if(a[i] < a[start]){
			temp[k] = a[i];
			++k;
		}else{	
			temp[ ((stop-start)-1) - (bk) ] = a[i];
			++bk;
		}
	}
	temp[k] = a[start];
	pivot = start+k;
	++k;
	k += bk;

	copy(temp, temp + k, a + start);
	delete temp;
}

template <class T>
void quicksort1(T a[], int start, int stop)
{
	if (stop - start > 1) {
		int pivot = start;
		
		partition1(a, start, stop, pivot);
		quicksort1(a, start, pivot);
		quicksort1(a, pivot + 1, stop);
	}
}

/* QUICKSORT STEP 3 */
// reusing partition from up above
template <class T>
void quicksort2(T a[], int start, int stop)
{
	if (stop - start > 1) {
		int pivot = start + rand() % (stop - start);
		
		partition1(a, start, stop, pivot);
		quicksort2(a, start, pivot);
		quicksort2(a, pivot + 1, stop);
	}
}

/* QUICKSORT STEP 4 */
template <class T>
void partition2(T a[], int start, int stop, int & pivot){

	int p = start;
	int q = start;
	int r = stop-1;
	swap(a[pivot], a[r]);
	T myPivot = a[r];
	while(q < r){
		if(/*(*/a[q] < myPivot)/* || (a[q] == myPivot))*/{
			swap(a[p], a[q]);
			++p;
		}
		++q;
	}
	swap(a[p], a[r]);
	pivot = p;
}

template <class T>
void quicksort3(T a[], int start, int stop)
{
	if (stop - start > 1) {
		int pivot = start + rand() % (stop - start);
		
		partition2(a, start, stop, pivot);
		quicksort3(a, start, pivot);
		quicksort3(a, pivot + 1, stop);
	}
}

/* PRINTS OUT ARRAYS */
void printArray(Integer a[], int start, int stop){
	for(int i = start; i < stop; i++){
		cout << a[i].value() << " ";
	}
	cout<<'\n';
}

/* MAIN  */
int main(){

	// Integer arrays --> you don't need the templates
	Integer incArray[10000];
	Integer decArray[10000];
	Integer randArray[10000];
	Integer randArray2[10000];
	Integer randArray3[10000];

	// filling each array with integers 1 - 10,000
	int currentNumInc = 1;
	int currentNumDec = 10000;
	int currentRandNum = 0;
	for(int i = 0; i < 10000; i++){
		incArray[i] = (currentNumInc);
		currentNumInc++;
		decArray[i] = (currentNumDec);
		currentNumDec--;
		currentRandNum = rand() % 10000 + 1;
		randArray[i] = (currentRandNum);
		currentRandNum = rand() % 10000 + 1;
		randArray2[i] = (currentRandNum);
		currentRandNum = rand() % 10000 + 1;
		randArray3[i] = (currentRandNum);
	}
	
	// RUN OF SELECTION SORT
	Integer_count = 0;
	selection_sort(incArray, 0, 10000);
	cout << "Selection sort on incArray: " << Integer_count << endl;

	Integer_count = 0;
	selection_sort(decArray, 0, 10000);
	cout << "Selection sort on decArray: " << Integer_count << endl;

	Integer_count = 0;
        selection_sort(randArray, 0, 10000);
        cout << "Selection sort on randArray: " << Integer_count << endl;

        Integer_count = 0;
        selection_sort(randArray2, 0, 10000);
        cout << "Selection sort on randArray2: " << Integer_count << endl;

	Integer_count = 0;
        selection_sort(randArray3, 0, 10000);
        cout << "Selection sort on randArray3: " << Integer_count << endl;

	// RUN OF MERGESORT
	Integer_count = 0;
        mergesort(incArray, 0, 5000, 10000);
	cout << "Mergesort on incArray: " << Integer_count << endl;

	Integer_count = 0;
	mergesort(decArray, 0, 5000, 10000);
	cout << "Mergesort on decArray: " << Integer_count << endl;

	Integer_count = 0;
        mergesort(randArray, 0, 5000, 10000);
        cout << "mergesort on randArray: " << Integer_count << endl;

        Integer_count = 0;
        mergesort(randArray2, 0, 5000, 10000);
        cout << "mergesort on randArray2: " << Integer_count << endl;

        Integer_count = 0;
        mergesort(randArray3, 0, 5000, 10000);
        cout << "mergesort on randArray3: " << Integer_count << endl;

	// RUN OF INSERTION SORT
	Integer_count = 0;
	insertion_sort(incArray, 0, 10000);
	cout << "Insertion sort on incArray: " << Integer_count << endl;
	
	Integer_count = 0;
	insertion_sort(decArray, 0, 10000);
	cout << "Insertion sort on decArray: " << Integer_count << endl;

	Integer_count = 0;
        insertion_sort(randArray, 0, 10000);
        cout << "Insertion sort on randArray: " << Integer_count << endl;

        Integer_count = 0;
        insertion_sort(randArray2, 0, 10000);
        cout << "Insertion sort on randArray2: " << Integer_count << endl;

        Integer_count = 0;
        insertion_sort(randArray3, 0, 10000);
        cout << "Insertion sort on randArray3: " << Integer_count << endl;

	// RUN OF QUICKSORT PART 2
	Integer_count = 0;
        quicksort1(incArray, 0, 10000);
	cout << "Quicksort on incArray: " << Integer_count << endl;

	Integer_count = 0;
	quicksort1(decArray, 0, 10000);
	cout << "Quicksort on decArray: " << Integer_count << endl;
	
	Integer_count = 0;
        quicksort1(randArray, 0, 10000);
        cout << "Quicksort on randArray: " << Integer_count << endl;

        Integer_count = 0;
        quicksort1(randArray2, 0, 10000);
        cout << "Quicksort on randArray2: " << Integer_count << endl;

        Integer_count = 0;
        quicksort1(randArray3, 0, 10000);
        cout << "Quicksort on randArray3: " << Integer_count << endl;

	// RUN OF QUICKSORT PART 3
        Integer_count = 0;
        quicksort2(incArray, 0, 10000);
	cout << "Quicksort 2 on incArray: " << Integer_count << endl;

	Integer_count = 0;
	quicksort2(decArray, 0, 10000);
	cout << "Quicksort 2 on decArray: " << Integer_count << endl;

	Integer_count = 0;
        quicksort2(randArray, 0, 10000);
        cout << "Quicksort 2 on randArray: " << Integer_count << endl;

        Integer_count = 0;
        quicksort2(randArray2, 0, 10000);
        cout << "Quicksort 2 on randArray2: " << Integer_count << endl;

        Integer_count = 0;
        quicksort2(randArray3, 0, 10000);
        cout << "Quicksort 2 on randArray3: " << Integer_count << endl;

	// RUN OF QUICKSORT PART 4
	Integer_count = 0;
        quicksort3(incArray, 0, 10000);
	cout << "Quicksort 3 on incArray: " << Integer_count << endl;

	Integer_count = 0;
	quicksort3(decArray, 0, 10000);
	cout << "Quicksort 3 on decArray: " << Integer_count << endl;

	Integer_count = 0;
        quicksort3(randArray, 0, 10000);
        cout << "Quicksort 3 on randArray: " << Integer_count << endl;

        Integer_count = 0;
        quicksort3(randArray2, 0, 10000);
        cout << "Quicksort 3 on randArray2: " << Integer_count << endl;

        Integer_count = 0;
        quicksort3(randArray3, 0, 10000);
        cout << "Quicksort 3 on randArray3: " << Integer_count << endl;
	
	// RUN OF STL SORT PART 6
	Integer_count = 0;	
	std::sort(incArray, incArray + 10000);
	cout << "STL sort on incArray: " << Integer_count << endl;
	
	Integer_count = 0;
	std::sort(decArray, decArray + 10000);
	cout << "STL sort on decArray: " << Integer_count << endl;

	Integer_count = 0;
        std::sort(randArray, randArray + 10000);
        cout << "STL sort on randArray: " << Integer_count << endl;

        Integer_count = 0;
        std::sort(randArray2, randArray2 + 10000);
        cout << "STL sort on randArray2: " << Integer_count << endl;

        Integer_count = 0;
        std::sort(randArray3, randArray3 + 10000);
        cout << "STL sort on randArray3: " << Integer_count << endl;

	return 0;

}







