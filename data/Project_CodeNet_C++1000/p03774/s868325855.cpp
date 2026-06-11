#include <iostream>
#include <cstdlib>

int main()
{  
  int N, M, a[50], b[50], c[50], d[50], goal_num[50], goal_dist[50];
  std::cin >> N >> M;
  
  for(int i = 0; i < N; i++)
  {
    std::cin >> a[i] >> b[i];
    goal_dist[i] = 1000000000;
  }

  for(int i = 0; i < M; i++)
  {
    std::cin >> c[i] >> d[i];  
  }
  
  for(int i = 0; i < N; i++)
  {
    for(int k = 0; k < M; k++)
    {
      int dist = (std::abs(a[i] - c[k]) + std::abs(b[i] - d[k]));
      if(dist < goal_dist[i])
      {
        goal_dist[i] = dist;
        goal_num[i] = k;
      }
    }
  }
  
  for(int i = 0; i < N; i++)
  {
    std::cout << (goal_num[i] + 1) << "\n";  
  }

  return 0;
}