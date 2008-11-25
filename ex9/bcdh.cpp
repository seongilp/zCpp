B0;136;0c#include <iostream>

using namespace std;

const int wide; // b. Class-wide constants
const string alice = "alice";

class Person 
{ 
public: 
  const void read(); // c. Constant member function
  void display(); 
  Person(string temp);
private: 
  const string name; 
  int age; 
}; 

int main()
{
  const Person p1 = new Person(alice);  // d. Constant reference parameter  
  					// h. Constant instance variables 
  return 0;
}
