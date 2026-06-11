#include <bits/stdc++.h>
using namespace std;
#define int ll
#define ll long long
#define I32_MAX 2147483647
#define I64_MAX 9223372036854775807LL
#define I64_MAX2 1223372036854775807LL
#define INF I64_MAX2
#define MOD 1000000007
// #define MOD 998244353
#define MEM_SIZE 101010
#define DEBUG_OUT true
#define ALL(x) (x).begin(), (x).end()

template <typename T>
void DEBUG(T e)
{
  if (DEBUG_OUT == false)
    return;
  std::cout << e << " ";
}
template <typename T>
void DEBUG(const std::vector<T> &v)
{
  if (DEBUG_OUT == false)
    return;
  for (const auto &e : v)
  {
    std::cout << e << " ";
  }
  std::cout << std::endl;
}
template <typename T>
void DEBUG(const std::vector<std::vector<T>> &vv)
{
  if (DEBUG_OUT == false)
    return;
  for (const auto &v : vv)
  {
    DEBUG(v);
  }
}
template <class T, class... Ts>
void DEBUG(T d, Ts... e)
{
  if (DEBUG_OUT == false)
    return;
  DEBUG(d);
  DEBUG(e...);
}
template <class T>
void corner(bool flg, T hoge)
{
  if (flg)
  {
    cout << hoge << endl;
    abort();
  }
}
template <typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template <typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

void solve(void)
{
  string s, t;
  cin >> s >> t;
  int q;
  cin >> q;
  vector<int> sum1(s.size() + 1, 0);
  vector<int> sum2(t.size() + 1, 0);
  // -- Note by MoSooN --
  // all s is transformed into A or AA or AAA
  // transform is inversible so seek substring of s ,t  is which of them. if same Yes not No
  // -- End note  --
  for (int i = 0; i < s.size(); i++)
  {
    sum1[i + 1] = sum1[i] + (s[i] == 'A') + 1;
  }
  for (int i = 0; i < t.size(); i++)
  {
    sum2[i + 1] = sum2[i] + (t[i] == 'A') + 1;
  }
  for (int i = 0; i < q; i++)
  {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--;
    c--;
    if ((sum1[b] - sum1[a]) % 3 == (sum2[d] - sum2[c]) % 3)
    {
      cout << "YES" << endl;
    }
    else
    {
      cout << "NO" << endl;
    }
  }

  return;
}

int32_t main(int32_t argc, const char *argv[])
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::cout << std::fixed;
  std::cout << std::setprecision(11);
  solve();

  return 0;
}
