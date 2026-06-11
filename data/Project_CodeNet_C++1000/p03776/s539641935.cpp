#include <bits/stdc++.h>
using namespace std;

int64_t nCk(int64_t n, int64_t k)
{
  int64_t res = 1;
  for (int64_t i = 1; i <= k; i++)
  {
    res = (res * (n - i + 1)) / i;
  }
  return res;
}

int main()
{
  long double N, A, B, ave = 0;
  cin >> N >> A >> B;
  vector<long double> V(N);
  map<long double, int64_t> mp;
  for (int i = 0; i < N; i++)
  {
    cin >> V[i];
    mp[V[i]]++;
  }
  sort(V.begin(), V.end());
  reverse(V.begin(), V.end());
  for (int i = 0; i < A; i++)
  {
    ave += (V.at(i) / A);
  }
  cout << fixed << setprecision(10) << ave << endl;
  int64_t ans = 1, n = A; // 残り何個選ぶ必要があるか
  if (mp[V[0]] <= A)
  {
    for (int i = 0; i < N; i++)
    {
      int64_t cnt = 1, j = i + 1; // cnt: V[i]を選べる個数
      while (j < N && V[j] == V[i])
      {
        cnt++;
        j++;
      }
      ans *= nCk(cnt, min(cnt, n));
      n -= min(cnt, n);
      if (n <= 0)
        break;
      i = j - 1;
    }
    cout << ans << endl;
  }
  else
  {
    for (int64_t k = A; k <= B; k++)
    {
      ans += nCk(mp[V[0]], k);
    }
    cout << ans - 1 << endl;
  }
}