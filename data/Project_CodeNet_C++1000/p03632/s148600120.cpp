#include <iostream>

int main()
{
  int A, B, C, D, result = 0;
  std::cin >> A >> B >> C >> D;
  
  int max, min;
  if(D > B)
  {
    max = B;
  }
  else
  {
    max = D; 
  }
  
  if(A > C)
  {
    min = A; 
  }
  else
  {
    min = C; 
  }
  
  if(B < C || D < A)
  {
    result = 0; 
  }
  else
  {
    result = max - min; 
  }
  
  std::cout << result;
  return 0;
}