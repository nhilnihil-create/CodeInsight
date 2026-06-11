#include <bits/stdc++.h>
#define rep(i, n) for (lli i = 0; i < (n); i++)
#define rrep(i, n) for (lli i = (n)-1; i >= 0; i--)
#define vall(x) (x).begin(), (x).end()
using namespace std;
using lli = long long int;
void YESNO(bool), YesNo(bool);
template <class T1, class T2>
bool chmin(T1 &l, const T2 &r);
template <class T1, class T2>
bool chmax(T1 &l, const T2 &r);
template <class T1, class T2>
void vadd(vector<T1> &v, T2 x);

#define int long long int
vector<lli> dp[5005];
void solve(long long N, long long K, std::vector<long long> a)
{
  vector<lli> b;
  rep(i, N) if (a[i] < K) b.push_back(a[i]);
  sort(b.begin(), b.end());
  lli up = b.size(), low = -1;
  // up is need, low is no need
  N = b.size();
  while (up - low > 1)
  {
    lli mid = (up + low) / 2;
    rep(i, N + 1) dp[i]
        .assign(K, 0);
    dp[0][0] = true;
    rep(i, N)
    {
      rep(j, K)
      {
        dp[i + 1][j] |= dp[i][j];
        if (mid != i && j + b[i] < K)
        {
          dp[i + 1][j + b[i]] |= dp[i][j];
        }
      }
    }
    bool ok = false;
    rrep(i, K)
    {
      if (dp[N][i])
      {
        if (i + b[mid] >= K)
          ok = true;
        break;
      }
    }
    (ok ? up : low) = mid;
  }
  cout << low + 1 << endl;
}

signed main()
{
  long long N;
  scanf("%lld", &N);
  long long K;
  scanf("%lld", &K);
  std::vector<long long> a(N);
  for (int i = 0; i < N; i++)
  {
    scanf("%lld", &a[i]);
  }
  solve(N, K, std::move(a));
  return 0;
}

// -- lib
void YESNO(bool b) { cout << (b ? "YES" : "NO") << endl; }
void YesNo(bool b) { cout << (b ? "Yes" : "No") << endl; }

template <class T1, class T2>
bool chmin(T1 &l, const T2 &r)
{
  return (l > r) ? (l = r, true) : false;
}

template <class T1, class T2>
bool chmax(T1 &l, const T2 &r)
{
  return (l < r) ? (l = r, true) : false;
}

template <class T1, class T2>
void vadd(vector<T1> &v, T2 x)
{
  for (auto &s : v)
    s += T2(x);
}
