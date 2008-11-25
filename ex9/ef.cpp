#include <iostream>

using namespace std;

class Array 
{ 
public: 
  float& operator[](int i); 
  Array(void);
private: 
  float c_array[10]; 
}; 

// e. Returning a reference
// f. Returning a constant reference

int main() 
{
  Array ar = new Array();
  float &far = ar[10]; // e. Returning a reference
  return 0;
}
