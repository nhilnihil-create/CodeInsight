#include <iostream>

int main()
{
  int N, M, city[50] = {0};
  std::cin >> N >> M;
  
  int start, end;
  for(int i = 0; i < M; i++)
  {
    std::cin >> start >> end;
    city[start - 1]++;
    city[end - 1]++;
  }

  for(int i = 0; i < N; i++)
  {
    std::cout << city[i] << "\n";
  }  

  return 0;
}