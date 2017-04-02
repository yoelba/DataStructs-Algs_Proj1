#include <iostream>
#include <array>

using namespace std;

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
	int_value = obj2.value();
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

// Main
int main(){


	return 0;
}
