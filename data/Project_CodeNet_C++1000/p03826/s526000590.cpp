#include <iostream>

int main()
{  
  int A, B, C, D, area;
  std::cin >> A >> B >> C >> D;
  
  if(A * B >= C * D)
  {
    area = A * B;
  }
  else
  {
    area = C * D;
  }
  
  std::cout << area;
  
  return 0;
}