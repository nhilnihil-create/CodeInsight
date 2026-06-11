#include <iostream>

int main()
{  
  int N;
  long power = 1;
  std::cin >> N;
  
  for(int i = 1; i <= N; i++)
  {
    power *= i;
    power = power % (1000000000 + 7);
  }
  
  std::cout << power;
  return 0;
}