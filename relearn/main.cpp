// Will Fisher

#include <iostream>
#include <string>

#include "spark.h"
#include "world.h"

int main()
{ 
  auto playing = true;
  Spark universe;
  
  while(playing) {
    playing = universe.handle_user_input();
  }

  return 0;
}
