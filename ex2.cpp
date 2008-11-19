#include <iostream>
#include <ctime>
#include <cstring>

using namespace std;

class Time
{
public:
  Time();
  virtual ~Time();
  void read(string);
  bool lessThan(const Time &t1);
  void display();
  Time subtract(const Time &t2);
private:
  int hour;
  int min;
};

int main(int argc, char *argv[])
{
  Time time1, time2, duration;
  time1.read("Enter time 1");
  time2.read("Enter time 2");
  if(time1.lessThan(time2)) {
    duration = time2.subtract(time1);
    cout << "Starting time was ";
    time1.display();
  }
  else {
    duration = time1.subtract(time2);
    cout << "Starting time was ";
    time2.display();
  }
  cout << "Duration was ";
  duration.display();
  return 0;
}

Time::Time() {
  hour = 0;
  min  = 0;
}

Time::~Time() {
}

void Time::read(string temp) {
  cout << temp << endl;
  cout << "Input hour ";
  cin >> hour;
  cout << endl << "Input minutes ";
  cin >> min;
  cout << endl;
}

bool Time::lessThan(const Time &temp) {
  int a = hour*60+min;
  int b = temp.hour*60+temp.min;
  if(a>=b)
    return false;
  else
    return true;
}

void Time::display() {
  cout << hour << ":" << min << endl;
}

Time Time::subtract(const Time &temp) {
  int a,b,sub;
  a   = hour*60+min;
  b   = temp.hour*60+temp.min;
  sub = a-b;
  a   = sub/60;
  b   = sub%60;
  Time test;
  test.hour = a;
  test.min  = b;
  return test;
}
