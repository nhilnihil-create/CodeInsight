#include <iostream>

void bubble_sort(int l[], int N)
{
  for(int i = 0; i < N; i++)
  {
    for(int k = i + 1; k < N; k++)
    {
      if(l[i] < l[k])
      {
        int temp = l[i];
        l[i] = l[k];
        l[k] = temp;
      }
    }
  }
}

int main()
{
  int N, K, l[50], length = 0;
  std::cin >> N >> K;
  
  for(int i = 0; i < N; i++)
  {
    std::cin >> l[i];
  }
  
  bubble_sort(l, N);

  for(int i = 0; i < K; i++)
  {
    length += l[i];
  }
  
  std::cout << length;
  return 0;
}