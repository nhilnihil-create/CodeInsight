#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std; //std::の省略のため
using ll = long long;

int main()
{
  int N, K;
  cin >> N >> K;
  int D[K];

  for (int i = 0; i < K; i++)
    cin >> D[i];

  int ans = N;
  int tmp;
  bool judge;

  while (ans <= 100000)
  {
    tmp = ans;
    judge = true;
    while (tmp != 0)
    {
      for (int i = 0; i < K; i++)
      {
        if ((tmp % 10) == D[i])
        {
          judge = false;
          break;
        }
      }

      if (!judge)
        break;

      tmp /= 10;
    }

    if (judge)
      break;
    else
      ans++;
  }

  cout << ans << endl;
}
