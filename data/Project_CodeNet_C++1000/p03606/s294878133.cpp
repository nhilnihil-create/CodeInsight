#include <iostream>
#include <string>
 
int main()
{
  int N, r, l, result = 0;
    
  std::cin >> N;
  
  for(int i = 0; i < N; i++)
  {
    int r, l;
    std::cin >> r >> l;
    result += (l - r + 1);
  }
  
  std::cout << result;
}