#include <iostream>
#include "counter.h"

using namespace std;

class LimitedCounter : public Counter {
 public:
  int min, max;
  LimitedCounter(int min0=0,int max0=0);
  LimitedCounter &operator++();
  LimitedCounter operator++(int);
  void reset();
  int getCount() const;
};

ostream &operator<<(ostream &out, const LimitedCounter &lc1);

Counter::Counter(int n0) {
  count = n0;
}

LimitedCounter::LimitedCounter(int min0, int max0) {
  min = min0;
  max = max0;
}

void LimitedCounter::reset() {
  min = 0;
}

int LimitedCounter::getCount() const {
  return min+1;}

ostream &operator<<(ostream &out, const LimitedCounter &lc1) {
  out << lc1.min;
  return out;
}

LimitedCounter &LimitedCounter::operator++() {
  if(min<10)
    min++;
  return *this;
}

LimitedCounter LimitedCounter::operator++(int) {
  LimitedCounter temp(min,max);
  if(min<10)
    min++;
  return temp;
}

int main(void) 
{ 
  LimitedCounter lc(0, 10);//initial value 0, upper limit 10
  cout << lc++ << endl;    //output should be 0 
  cout << ++lc << endl;    //output should be 2 
  lc.reset(); 
  for (int i = 0; i < 15; i++){ 
    lc++; cout << lc << endl; 
  } 
  cout << lc.getCount() << endl; 
  return 0; 
} 
