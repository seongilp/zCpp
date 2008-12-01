#include <vector>
#include <iostream>

using namespace std;

int main() {
  vector<float> fv;
  vector<float>::iterator fvi;
  float in=0,sum=0,avr=0;
  while(1) { 
    cout << "Input numbers : ";
    cin >> in;
    if(in<0)
      break;
    fv.push_back(in);
  }
  cout << "< Result >" << endl;
  cout << "Vector's capacity is " << fv.capacity() << endl;
  cout << "Vector's size is " << fv.size() << endl;
  cout << "<Vector's elements> " << endl;
  for(fvi = fv.begin();fvi!=fv.end();fvi++) {
    cout << *fvi << endl;
    sum = sum+*fvi;
  }
  avr = sum/fv.size();
  cout << "Vector's average is " << avr << endl;
  return 0;
}
