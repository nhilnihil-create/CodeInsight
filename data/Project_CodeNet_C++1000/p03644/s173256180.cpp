#include <iostream>

int divided_by_2_count(int num)
{
  int count = 0;
  while(num % 2 == 0)
  {
    num /= 2;
    count++;
  }
  
  return count;
}

int main()
{
  int N, result = 1, max_count = 0;
  std::cin >> N;
  
  for(int i = 1; i <= N; i++)
  {
    int count = divided_by_2_count(i);
    if(count > max_count)
    {
      max_count = count;
      result = i;
    }
  }
  
  std::cout << result;
  return 0;
}