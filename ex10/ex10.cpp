#include <iostream>
#include "counter.h"

using namespace std;

class LimitedCounter {
 public:
  LimitedCounter(int min0=0,int max0=0);
  LimitedCounter &operator++();
  LimitedCounter operator++(int);
  void reset();
  int getCount() const;
  friend ostream &operator<<(ostream &out, const LimitedCounter &lc1);
private:
  Counter c;
  int min, max;
};

LimitedCounter::LimitedCounter(int min0, int max0) : c(min0) {
  min = min0;
  max = max0;
}

void LimitedCounter::reset() {
  c.reset();
}

int LimitedCounter::getCount() const {
  return c.getCount();
}

ostream &operator<<(ostream &out, const LimitedCounter &lc1) {
  out << lc1.getCount();
  return out;
}

LimitedCounter &LimitedCounter::operator++() {
  if(max>c.getCount())
    c++;
  return *this;
}

LimitedCounter LimitedCounter::operator++(int) {
  LimitedCounter temp(min,max);
  if(max>c.getCount())
    c++;
  return temp;
}

int main(void) 
{
  Counter c1(0); 		 
  Counter *c2 = new Counter(0);	// extra

  LimitedCounter lc(0, 10);	//initial value 0, upper limit 10
  
  cout << lc++ << endl;		//output should be 0 
  cout << ++lc << endl;		//output should be 2 
  lc.reset();
 
  for (int i = 0; i < 15; i++){ 
    lc++; cout << lc << endl; 
  } 
  cout << lc.getCount() << endl; 
  return 0; 
}
