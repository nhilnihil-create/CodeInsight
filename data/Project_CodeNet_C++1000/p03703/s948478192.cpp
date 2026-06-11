#include <bits/stdc++.h>
using namespace std;

template <typename T>
class FenwickTree
{
public:
  int N;
  vector<T> dat;

  FenwickTree(int n, T m = 0)
  {
    init(n, m);
  }

  void init(int n, int m)
  {
    N = n;
    dat.resize(n + 1);
    for (int i = 0; i < dat.size(); i++)
    {
      dat[i] = m;
    }
  }

  int64_t sum(int i)
  {
    T s = 0;
    while (i > 0)
    {
      s += dat[i];
      i -= i & -i;
    }
    return s;
  }

  void add(int i, T x)
  {
    while (i <= N)
    {
      dat[i] += x;
      i += i & -i;
    }
  }
};

int main()
{
  int64_t N, K;
  cin >> N >> K;
  vector<int64_t> A(N), S(N + 1, 0); // l <= x <= r -> S[r+1] - S[l]
  for (int i = 0; i < N; i++)
  {
    cin >> A.at(i);
  }
  for (int i = 0; i < N; i++)
  {
    S.at(i + 1) = S.at(i) + A.at(i);
  }
  vector<int64_t> B(N + 1);
  for (int i = 0; i <= N; i++)
  {
    B.at(i) = S.at(i) - K * i;
  }
  auto C = B;
  sort(C.begin(), C.end());
  int cnt = 1;
  map<int64_t, int64_t> mp;
  mp[C[0]] = 1;
  for (int i = 1; i <= N; i++)
  {
    if (C.at(i) > C.at(i - 1))
    {
      cnt++;
    }
    mp[C[i]] = cnt;
  }
  for (int i = 0; i <= N; i++)
  {
    B.at(i) = mp[B.at(i)];
  }
  int64_t ans = 0;
  FenwickTree<int> ft(cnt + 1);
  for (int i = 0; i <= N; i++)
  {
    ans += ft.sum(B.at(i));
    ft.add(B.at(i), 1);
  }
  cout << ans << endl;
}