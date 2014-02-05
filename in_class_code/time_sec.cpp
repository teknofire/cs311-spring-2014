// TimeSec class
// method description
// Pre: 
//  0 <= hours <= 24
//  0 <= minutes < 60
//  0 <= seconds < 60
 
class TimeSec
{
public:
  // constructor
  // takes hour minute seconds and stores it internally
  TimeSec (hours=0,mins=0,seconds=0);

private:
  int seconds;
};

