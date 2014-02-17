// allocate1
// Pre: 
//   size >= 0
// Post:
//   ipr points to array of size int's, allocated with new
// May throw std::bad_alloc
void allocate1(size_t size, int * & iptr)
{
  iptr = new int(size);
}

// allocate2
// Pre: 
//   size >= 0
// Post:
//   
void allocate2(size_t size, int * &iptr1, int * &iptr2)
{
  iptr1 = new int(size);
  try {
    iptr2 = new int(size);    
  }
  catch (...)
  {
    delete [] iptr1;
    throw;
  }
  
}

int main (int argc, char const *argv[])
{
  int * ptr1;
  int * ptr2;
  bool allocate1Success = false;
  bool allocate2Success = false;
  
  try
  {
    allocate1(10, ptr1);
    allocate1Success = true;
  }
  catch(std::bad_alloc &e)
  {
  }
  
  if (allocate1Success)
    delete [] ptr1;
  
  allocate2(10, ptr1, ptr2);
  
  /* code */
  return 0;
}