#include <iostream>
#include <ctime>
#include <cstring>

using namespace std;

class Time
{
public:
  Time(int hour0=0, int min0=0);
  virtual ~Time();
  friend ostream& operator<<(ostream &out, const Time &t); // output
  friend istream& operator>>(istream &in, Time &t);	   // input
  Time &operator-(const Time &t);			   // subtract
  const Time &operator=(const Time &t);			   // 
  Time& operator++();		                           // pre-increment
  Time operator++(int);	                                   // post-increment
  bool operator<(const Time &t);                           // lessThan  
  
private:
  int hour;
  int min;
};

int main(int argc, char *argv[])
{
  Time time1, time2, duration;
  cout << "Enter time 1";
  cin >> time1;
  cout << "Enter time 2";
  cin >> time2;
  if(time1 < time2)
    {
      duration = time2 - time1;
      cout << "Stating time was " << time1;
    }
  else
    {
      duration = time1 - time2;
      cout << "Stating time was " << time2;
    }
  cout << "Duration was " << duration;

  Time time3;
  cout << "Enter time 3";
  cin >> time3;
  cout << time3++ << endl;
  cout << ++time3 << endl;

  return 0;
}

Time::Time(int hour0, int min0) {
  hour = hour0;
  min = min0;
}
Time::~Time() {
}

istream &operator>>(istream &in, Time &temp) {
  cout << endl << "Input hour ";
  in >> temp.hour;
  cout << endl << "Input minutes ";
  in >> temp.min;
  cout << endl;
}


bool Time::operator<(const Time &temp) {
  int a = hour*60+min;
  int b = temp.hour*60+temp.min;
  if(a>=b)
    return false;
  else
    return true;
}

const Time &Time::operator=(const Time &t)
{
  hour = t.hour;
  min = t.min;
  return *this;
}

ostream &operator<<(ostream &out, const Time &t) {
  out << t.hour << ":" << t.min << endl;
}

Time &Time::operator-(const Time &temp) {
  int a,b,sub;
  a   = hour*60+min;
  b   = temp.hour*60+temp.min;
  sub = a-b;
  a   = sub/60;
  b   = sub%60;
  static Time test;
  test.hour = a;
  test.min  = b;
  return test;
}

Time &Time::operator++() {
  hour++;
  min++;
  return *this;
}

Time Time::operator++(int) {
  Time temp(hour,min);
  hour++;
  min++;
  return temp;
}
