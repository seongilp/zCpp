#include <iostream>
#include <cstring>

using namespace std;
 
class Person {
public:
  Person(const char *name0="", int noc0=0,int age1=0, int age2=0); // constructor
  Person(const Person &p);	// copy constructor
  ~Person();			// destructor
  friend ostream &operator<<(ostream &out, const Person &p);
  static int num;

private:
  char	*name;			// name
  int	 noc;			// number of children
  int	*ages;			// ages of children
};

Person::Person(const char *name0, int noc0, int age1, int age2) {
  name	  = new char[strlen(name0)+1];	
  strcpy (name,name0);			
  noc = noc0;
  ages	  = new int[noc+1];		
  if(noc0 != 0) {
    // ages = new int[noc+1];
    ages[0] = age1;
    ages[1] = age2;
  }
  num++;
  cout << "Ref num is " << num << endl;  
}

ostream &operator<<(ostream &out, const Person &p)
{
  out << "Name is " << p.name << endl;
  out << "Number of Children: " << p.noc << endl;
  for(int i=0;i<p.noc;i++) {
    cout << "Age is: " << p.ages[i] << endl;
  }
  return out;
}

Person::~Person() {
  delete ages;
  cout << "desturctor is done" << endl;
  num--;
}

int Person::num = 0;

int main(void) {
  Person **pArray;
  pArray = new Person*[3];
  pArray[0] = new Person("aaaa");
  pArray[1] = new Person("bbbb",1,1);
  pArray[2] = new Person("cccc",2,1,2);
  cout << "Person 1: " << *pArray[0] << endl;
  cout << "Person 2: " << *pArray[1] << endl;
  cout << "Person 3: " << *pArray[2] << endl;
  for(int i=0;i<3;i++)
    delete pArray[i];
  delete[] pArray;
  return 0;
}
