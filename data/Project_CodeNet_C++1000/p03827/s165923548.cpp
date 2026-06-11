#include <bits/stdc++.h>

int main(void)
{
  int N;
  std::string S;
  std::cin >> N >> S;

  int x = 0;
  int max_x = 0;
  for (int i = 0; i < N; i++) {
    if (S[i] == 'I') {
      x++;
    }
    else if (S[i] == 'D') {
      x--;
    }
    
    max_x = std::max(x, max_x);
  }
  std::cout << max_x << std::endl;

  return 0;
}