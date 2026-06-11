#include <bits/stdc++.h>
using namespace std;
#define INFTY 20000000000

int N, K;
vector<int> A(15);

int main()
{
  cin >> N >> K;
  for (int i = 0; i < N; i++)
  {
    cin >> A.at(i);
  }
  long long min_cost = INFTY, tmp;
  int obstacle;
  // O(N×2^N)のアルゴリズム
  for (int bit = 0; bit < (1 << N); bit++)
  {
    if (__builtin_popcount(bit) != K)
    {
      continue;
    }
    tmp = 0;
    obstacle = 0;
    for (int i = 0; i < N; i++)
    {
      if (bit & (1 << i))
      {
        if (obstacle >= A.at(i))
        {
          tmp += obstacle - A.at(i) + 1;
          obstacle++;
        }
        else
        {
          obstacle = A.at(i);
        }
      }
      else
      {
        obstacle = max(obstacle, A.at(i));
      }
    }
    min_cost = min(min_cost, tmp);
  }
  cout << min_cost << endl;
}