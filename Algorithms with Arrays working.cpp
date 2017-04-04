#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

//-----------------------------------------------------

int Integer_count; // Global variable

// Class Integer
template <class T>
class Integer{
public:
        Integer() { Integer_count = 0; } // default constructor
        Integer( int x ) { Integer_count = x; } // constructor sets x
        Integer( const T & obj2 ); // copy other Integer, increment counter
        int value() { return int_value; }
        bool operator<( const T & obj2 );
        void operator=( const T & obj2 );
private:
        int int_value;

};

template <class T>
inline Integer<T>::Integer( const T & obj2 ){ // copy constructor
        Integer_count++;
        // copy the value of the other Integer object 

        int_value = * obj2.value();
}

template <class T>
inline bool Integer<T>::operator<( const T & obj2 ){
        Integer_count++;
        if(value() < obj2.value()) return true;
        else return false;
}

template <class T>
inline void Integer<T>::operator=( const T & obj2 ){
        Integer_count++;
        int_value = obj2.value();
}

//-----------------------------------------------------

// selection sort from sec 3.1
void selection_sort(T a[], int start, int stop){

        while(stop - start > 1){
                auto itr_max = std::max_element(a + start, a + stop);
                std::swap(*itr_max, a[stop - 1]);
                --stop;
        }
}

// mergesort from sec 3.3
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

// you also need to include implementation from steps 1-4 when Yoel is done

int main(){

        // Array containing Integer objects 1-n
        int a[] = {1, 2, 4, 3, 7, 12, 34, 5};

        // STL sort algorithm
        std::sort(a, a + 8); // (array name, array name + size of array)

// WHY ARE THESE ARRAYS OBJECTS OF THE CLASS NOW?
        /*Integer<int>*/ int incArray[10000];
        /*Integer<int>*/ int decArray[10000];
        /*Integer<int>*/ int randArray[10000];
        /*Integer<int>*/ int randArray2[10000];
        /*Integer<int>*/ int randArray3[10000];

/////// THESE ARE TAKING FROM THE '=' OPERATION WE MADE ///////
        // filling array with increasing integers from 1 - 10,000
        int currentNumInc = 1;
        for(int i = 0; i < 10000; i++){
                incArray[i] = currentNumInc;
                currentNumInc++;
        }

        // filling array with decreasing integers from 10,000 - 1
        int currentNumDec = 10000;
        for(int i = 10000; i > 0; i--){
                decArray[i] = currentNumDec;
                currentNumDec--;
        }

        // filling arrays of size 10,000 with random values
        int currentRandNum;
        for(int i = 1; i < 10000; i++){
                currentRandNum = rand() % 10000 + 1;
                randArray[i] = currentRandNum;
        }

        for(int i = 1; i < 10000; i++){
                currentRandNum = rand() % 10000 + 1;
                randArray2[i] = currentRandNum;
        }

        for(int i = 1; i < 10000; i++){
                currentRandNum = rand() % 10000 + 1;
                randArray3[i] = currentRandNum;
        }

        return 0;
}
