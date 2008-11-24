#include <iostream>
#include <cstring>

using namespace std;
 
class Person {
public:
  Person(const char *name0="", int noc0=0,int age1=0, int age2=0); // constructor
  Person(const Person &p);	// copy constructor
  ~Person();			// destructor
  friend ostream &operator<<(ostream &out, const Person &p);

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
}

int main(void) { 
  Person p1("aaaa",0);
  Person p2("bbbb",1,1);
  Person p3("cccc",2,1,2);
  cout << "Person 1: " << p1 << endl;
  cout << "Person 2: " << p2 << endl;
  cout << "Person 3: " << p3 << endl;
  return 0;
}
