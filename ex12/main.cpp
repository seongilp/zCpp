#include <iostream>
#include "counter.h"

using namespace std;

void UseCounter(Counter &c, int n);
void UseCounter(LimitedCounter &lc, int n2);

int main() 
{
  Counter c1(10);
  LimitedCounter lc1(5,10);

  UseCounter(c1,6);
  UseCounter(lc1,10);

  int i = c1.getCount();
  int j = lc1.getCount();
  cout << "c1 value is " << i << endl;
  cout << "lc1 value is " << j << endl;
 
  return 0;
}

void UseCounter(Counter &c, int n)
{
  for(int i=0;i<n;i++)
    c++;
}

void UseCounter(LimitedCounter &lc, int n2)
{
 // lc.max = n2;
}
