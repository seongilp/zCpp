#include <iostream>
#include "counter.h"

using namespace std;

void UseCounter(Counter &c, int n);

int main() 
{
  Counter c1(10);
  //Counter c2(5);			       
  LimitedCounter lc1(5);

  UseCounter(c1,6);
  UseCounter(lc1,10);

  int i = c1.getCount();
  cout << "c1 value is " << i;
  cout << c2 << endl;
 

  return 0;
}

void UseCounter(Counter &c, int n)
{
  for(int i=0;i<n;i++)
    c++;
}
