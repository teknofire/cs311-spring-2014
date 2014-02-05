/* Timesec.cpp */

#include "timesec.h"
#include <sstream>
using std::ostringstream;

// TimeSec::TimeSec
// method description
// Pre: (hours*60+minutes)*60+seconds) < 24*60*60
// Post: 
TimeSec::TimeSec(unsigned int hours, unsigned int minutes, unsigned int seconds)   
  :_seconds((hours*60+minutes)*60+seconds)
{
}

//Precondition: None
//Postcondition:  time has been set to hours;minutes.seconds
void TimeSec::setTime(unsigned int hours, unsigned int minutes, unsigned int seconds)
{
  _seconds = ((hours*60+minutes)*60+seconds);
}

//Precondition: None
//Postcondition:
string TimeSec::toString() const
{
  ostringstream output;
  output << getHours() << ":" << getMinutes() << "." << getSeconds();
  return output.str();
}

//Precondition: None
TimeSec& TimeSec::operator++() //canonical
{
  ++_seconds;
  if(_seconds == 24*60*60)
    _seconds = 0;
  
  return *this;
}

//Precondition: None
TimeSec TimeSec::operator++(int)
{
  TimeSec temp;
  ++(*this);
  return temp;
}

//Precondition: None
//Postcondition: time is decremented and 
TimeSec& TimeSec::operator--()
{
  if(_seconds == 0)
    _seconds = 60 * 60 * 24 - 1;
  else
    --_seconds;
  
  return *this;
}

//Precondition: None
TimeSec TimeSec::operator--(int)
{
  TimeSec temp;
  --(*this);
  return temp;
}

//Precondition: None
unsigned int TimeSec::getSeconds() const
{
  return _seconds%60;
}

//Precondition: None
unsigned int TimeSec::getMinutes() const
{
  return (_seconds/60)%60;
}

//Precondition: None
unsigned int TimeSec::getHours() const
{
  return _seconds/(60*60);
}

//Precondition: None
//Postcondition: returns true if lhs is equal to rhs
bool operator==(const TimeSec& lhs, const TimeSec& rhs)
{
  return (lhs._seconds == rhs._seconds);
}

//Precondition: None
//Postcondition: returns true if lhs is not equal to rhs
bool operator!=(const TimeSec& lhs, const TimeSec& rhs)
{
  return !(lhs == rhs);
}

//Precondition: None
bool operator<(const TimeSec& lhs, const TimeSec& rhs)
{
  return (lhs._seconds < rhs._seconds);
}

//Precondition: None
bool operator>(const TimeSec& lhs, const TimeSec& rhs)
{
  return (rhs < lhs);
}

//Precondition: None
bool operator<=(const TimeSec& lhs, const TimeSec& rhs)
{
  return !(lhs < rhs);
}

//Precondition: None
bool operator>=(const TimeSec& lhs, const TimeSec& rhs)
{
  return !(rhs < lhs);
}

//Precondition: os is not in an error state
//Postcondition: toprint has been printed in human format to os
ostream& operator<<(ostream& os, const TimeSec& toprint)
{
  return os << toprint.toString();
}