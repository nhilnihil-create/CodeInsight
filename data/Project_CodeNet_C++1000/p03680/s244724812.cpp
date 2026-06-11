#include <iostream>

int main()
{
  int N, a[100000], next = 1, count = 0;
  std::cin >> N;
  
  for(int i = 0; i < N; i++)
  {
    std::cin >> a[i];
  }
  
  for(int i = 0; i < N && next != 2; i++)
  {
    next = a[next - 1];
    count++;
  }

  if(next != 2)
  {
    count = -1;
  }
  
  std::cout << count;
  return 0;
}