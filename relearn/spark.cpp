#include <iostream>
#include <string>
#include "spark.h"


bool Spark::handle_user_input(void) {
  char cmd = ask_for_action();
  
  std::cout << cmd << std::endl;
  
  return false;
};

char Spark::ask_for_action(void) {
  char cmd;
  
  std::cout << "What do you want to do? ";
  std::cin >> cmd;
  std::cin.ignore();  
    
  return cmd;
}
