#include <iostream>
#include <cstring>

using namespace std;
 
class Person {
public:
  Person(const char *name0="", int noc0=0,int age1=0, int age2=0, int age3=0); // constructor
  //Person(const char *name1="", int noc1=0,int age4=0, int age5=0);
  Person(const Person &p);	// copy constructor
  ~Person();			// destructor
  void		 display();
  friend ostream &operator<<(ostream &out, const Person &p);
  const	 Person	 &operator=(const Person &p); 
  Person  operator+(const Person &p);

private:
  char	*name;			// name
  int	 noc;			// number of children
  int	*ages;			// ages of children
};

Person::Person(const char *name0, int noc0, int age1, int age2, int age3) {
  name	  = new char[strlen(name0)+1];	
  strcpy (name,name0);			
  noc	  = noc0;			
  ages	  = new int[noc+1];		
  ages[0] = age1;			
  ages[1] = age2;			
  ages[2] = age3;			
}

void Person::display() {
  cout << "Name is " << name << endl;
  cout << "Number of Children: " << noc << endl;
  for(int i=0; i<noc; i++) {
    cout << "Age is: " << ages[i] << endl;
  }
}

Person Person::operator+(const Person &p1) {
  Person couple;
  couple.noc = noc + p1.noc;
  //couple.name = new char[strlen(name)+1];
  strcpy(couple.name, name);
  strcat(couple.name, " and ");
  strcat(couple.name, p1.name);
  for (int i = 0; i < couple.noc; i++)
  {
    if(i<noc)
      couple.ages[i] = ages[i];
    else
      couple.ages[i] = p1.ages[i-noc];
  }
  return couple;
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

const Person &Person::operator=(const Person &p) {
  name		 = new char[strlen(p.name)+1];	
  strcpy(name, p.name);				
  noc		 = p.noc;			
  ages		 = new int[p.noc];		
  for(int i = 0;i<p.noc;i++) {
    ages[i]	 = p.ages[i];
  }

  return *this;
}

Person::~Person() {
  //	delete ages;
}

int main(void) { 
  Person p1("Matti", 3, 10, 12, 16); 
  Person p2("Maita", 2, 5, 7);
  Person couple;
  cout << "Person 1: " << p1 << endl;
  cout << "Person 2: " << p2 << endl;
  couple = p1 + p2;
  cout << "Couple: " << couple << endl;

  return 0;
}
