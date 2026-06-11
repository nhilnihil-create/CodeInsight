#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rrep(i, n) for (ll i = (n - 1); i >= 0; --i)
#define blank(ans) cout << (ans) << " ";
#define mp(p, q) make_pair(p, q)
#define mt(p, q, r) make_tuple(p, q, r)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef string str;

typedef vector<ll> vll;
typedef vector<ld> vd;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<str> vs;
typedef vector<vector<ll>> vvll;
typedef vector<vector<ld>> vvd;
typedef vector<vector<bool>> vvb;
typedef vector<vector<char>> vvc;
typedef vector<vector<str>> vvs;
typedef vector<pair<ll, ll>> vpll;
typedef vector<tuple<ll, ll, ll>> vtlll;

const ld PI = acos(-1.0);
const ll MAX = 9000000000000000000;
const ll MIN = -9000000000000000000;
const ld DMAX = 4500;
const ld DMIN = -4500;
const ll MOD = 1000000007;

template <typename T>
void fin(T a)
{
  cout << a << endl;
  exit(0);
}

ll gcd(ll a, ll b)
{
  return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b)
{
  return a * b / gcd(a, b);
}

//実行部
void Main()
{
  ll a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  a *= 100;
  b *= 100;
  ld flag = 0;
  ll sw = f, s = 0;
  for(ll A = 0;A * a <= f;A++)
  {
    for(ll B = 0;A * a + B * b <= f;B++)
    {
      for(ll C = 0;(e + 100) * 100 * C * c <= 100 * e *(A * a + B * b + C * c)&&A * a + B * b + C * c <= f;C++)
      {
        for(ll D = 0;(e + 100) * 100 * (C * c + D * d) <= 100 * e * (A * a + B * b + C * c + D * d)&&A * a + B * b + C * c + D * d <= f;D++)
        {
          if (flag <= 100. * (C * c + D * d) / (A * a + B * b + C * c + D * d))
          {
            flag = 100. * (C * c + D * d) / (A * a + B * b + C * c + D * d);
            sw = A * a + B * b + C * c + D * d;
            s = C * c + D * d;
          }
        }
      }
    }
  }
  cout << sw << " " << s << endl;
}

//前処理
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(20); //高精度少数表示
  Main();
  return 0;
}

/*
//test時
  g++ test.cpp -o test;./test
*/
