#include <bits/stdc++.h>
using namespace std;
#define INF 100000000000

int main()
{
  int N, K;
  cin >> N >> K;
  vector<long long> a(N);
  long long ans = INF;
  for (int i = 0; i < N; ++i)
  {
    cin >> a.at(i);
  }
  for (int i = 0; i < 1 << N; ++i)
  {
    if (__builtin_popcountll(i) != K)
    {
      continue;
    }
    long long ans_i = 0, max_hight = 0;
    for (int j = 0; j < N; ++j)
    {
      if (1 << (N - j - 1) & i)
      {
        if (max_hight >= a.at(j))
        {
          ans_i += max_hight - a.at(j) + 1;
          max_hight += 1;
        }
      }
      max_hight = max(max_hight,a.at(j));
    }
    // bitset<15> bs(i);
    // cout << bs << endl;
    // cout << ans_i << endl;
    ans = min(ans, ans_i);
  }
  cout << ans << endl;
}
