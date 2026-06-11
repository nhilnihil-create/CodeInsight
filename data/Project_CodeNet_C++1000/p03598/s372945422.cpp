#include <iostream>
#include <string>
 
int main()
{
  int N, K, x[100], result = 0;
  std::cin >> N >> K;
  
  for(int i = 0; i < N; i++)
  {
    std::cin >> x[i];
  }
  
  for(int i = 0; i < N; i++)
  {
    if(K - x[i] > x[i])
    {
      result += x[i] * 2;
    }
    else
    {
      result += (K - x[i]) * 2;      
    }
  }
  
  std::cout << result;
}