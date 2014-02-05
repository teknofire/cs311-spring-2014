/* timesec.h */

#ifndef TIMESEC_H_VM7I4VUY
#define TIMESEC_H_VM7I4VUY

#include <string>
using std::string;
#include <iostream>
using std::ostream;

// Class invariants
// 0 <= _seconds < 24*60*60
class TimeSec
{
friend bool operator==(const TimeSec &lhs, const TimeSec &rhs);
friend bool operator<(const TimeSec &lhs, const TimeSec &rhs);

public:
  TimeSec(unsigned int hours=0, unsigned int minutes=0, unsigned int seconds=0);
  //using sliently written copy ctr, copy assignment, and dtor
  string toString() const;
  unsigned int getSeconds() const;
  unsigned int getMinutes() const;
  unsigned int getHours() const;
  TimeSec & operator++();   //pre-increment
  TimeSec operator++(int);  //post-increment
  TimeSec & operator--();   //pre-increment
  TimeSec operator--(int);  //post-increment
  void setTime(unsigned int hours=0, unsigned int minutes=0, unsigned int seconds=0);
  
private:
  unsigned int _seconds;
};

bool operator==(const TimeSec &lhs, const TimeSec &rhs);
bool operator==(const TimeSec &lhs, const TimeSec &rhs);
bool operator!=(const TimeSec &lhs, const TimeSec &rhs);
bool operator<(const TimeSec &lhs, const TimeSec &rhs);
bool operator>(const TimeSec &lhs, const TimeSec &rhs);
bool operator>=(const TimeSec &lhs, const TimeSec &rhs);  
bool operator<=(const TimeSec &lhs, const TimeSec &rhs);
ostream & operator<<(ostream &, const TimeSec &toprint);

#endif /* end of include guard: TIMESEC_H_VM7I4VUY */
