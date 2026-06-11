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
lli N, K;
vector<lli> A, B;
void solve(long long N, long long K, std::vector<long long> A,
           std::vector<long long> B)
{
  // K最上位ビットが立ってないもののみ使う場合はすべて使える
  // Kの最上位ビットがたってるかつ, それ未満の場合
  lli ans = 0;

  rep(j, N) if ((A[j] & ~K) == 0) ans += B[j];
  rrep(i, 31)
  {
    // (i) not use
    lli ret = 0;
    if ((K >> i) & 1)
    {
      // i番目ビットを使わない => iより大きいビットがK（ビットで)以下のものは使える
      rep(j, N) if (((A[j] >> i) & (~(K >> i))) == 0 && ((A[j] >> i) & 1) == 0) ret += B[j];
      //cout << i << " " << ret << endl;
      chmax(ans, ret);
    }
    // (ii) use
  }
  cout << ans << endl;
}
signed main()
{
  long long N;
  scanf("%lld", &N);
  long long K;
  scanf("%lld", &K);
  std::vector<long long> A(N);
  std::vector<long long> B(N);
  for (int i = 0; i < N; i++)
  {
    scanf("%lld", &A[i]);
    scanf("%lld", &B[i]);
  }
  solve(N, K, std::move(A), std::move(B));
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
