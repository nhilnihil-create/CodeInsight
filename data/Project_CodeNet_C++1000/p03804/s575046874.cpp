#include <iostream>
#include <string>
int main()
{  
  int N, M;
  std::string A[50], B[50], result = "No";
  std::cin >> N >> M;
  
  for(int i = 0; i < N; i++)
  {
    std::cin >> A[i];
  }
  
  for(int i = 0; i < M; i++)
  {
    std::cin >> B[i]; 
  }

  for(int i = 0; i <= N - M; i++)
  {
    for(int j = 0; j <= N - M; j++)
    {
      for(int k = 0; k < M; k++)
      {
        if(A[j + k].compare(i, M, B[k]) != 0)
        {
          break;
        }
        else if(k == M - 1)
        {
          result = "Yes";
        }
      }
    }
  }
  
  std::cout << result;
  return 0;
}