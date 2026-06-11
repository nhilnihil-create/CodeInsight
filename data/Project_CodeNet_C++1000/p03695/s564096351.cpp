#include <iostream>

int main()
{
  int N, rate[9] = {0};
  std::cin >> N;
  
  int score;
  for(int i = 0; i < N; i++)
  {
    std::cin >> score;
    if(score < 3200)
    {
      rate[score / 400]++;
    }
    else
    {
      rate[8]++;
    }
  }
  
  int type_min = 0, type_max = 0;
  for(int i = 0; i < 8; i++)
  {
    if(rate[i] > 0)
    {
      type_min++;
    }
  }
  
  if(type_min == 0 && rate[8] > 0)
  {
    type_min = 1;
    type_max = type_min + rate[8] - 1;
  }
  else
  {
    type_max = type_min + rate[8];  
  }
  
  std::cout << type_min << " " << type_max;  
  return 0;
}