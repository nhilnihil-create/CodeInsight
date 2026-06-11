/**
*    author:  yuya1234
*    created: 01.07.2020 15:24:38
**/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
#define REPD(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = a; i <= (ll)(b); i++)
#define FORD(i, a, b) for (ll i = a; i >= (ll)(b); i--)
#define FORV(i, v) for (auto i = v.begin(); i != v.end(); i++)

#define ALL(v) (s).begin(), (s).end()
#define SORT(s) sort((s).begin(), (s).end())
#define SORTD(s) sort((s).rbegin(), (s).rend())
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());

#define SZ(x) ((int)(x).size())
#define MEMSET(v, h) memset((v), h, sizeof(v))
template <typename T>
struct Combination
{
  vector<T> _fact, _rfact, _inv;

  Combination(int sz) : _fact(sz + 1), _rfact(sz + 1), _inv(sz + 1)
  {
    _fact[0] = _rfact[sz] = _inv[0] = 1;
    for (int i = 1; i <= sz; i++)
      _fact[i] = _fact[i - 1] * i;
    _rfact[sz] /= _fact[sz];
    for (int i = sz - 1; i >= 0; i--)
      _rfact[i] = _rfact[i + 1] * (i + 1);
    for (int i = 1; i <= sz; i++)
      _inv[i] = _rfact[i] * _fact[i - 1];
  }

  inline T fact(int k) const { return _fact[k]; }

  inline T rfact(int k) const { return _rfact[k]; }

  inline T inv(int k) const { return _inv[k]; }

  T P(int n, int r) const
  {
    if (r < 0 || n < r)
      return 0;
    return fact(n) * rfact(n - r);
  }

  T C(int p, int q) const
  {
    if (q < 0 || p < q)
      return 0;
    return fact(p) * rfact(q) * rfact(p - q);
  }

  T H(int n, int r) const
  {
    if (n < 0 || r < 0)
      return (0);
    return r == 0 ? 1 : C(n + r - 1, r);
  }
};

int main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int n, p;
  cin >> n >> p;

  ll cnt0=0, cnt1=0, tmp;
  REP(i, n)
  {
    cin >> tmp;
    if (tmp % 2 == 0)
      cnt0++;
    else
      cnt1++;
  }

  ll ans = 0;
  Combination<double> a(50);
  if (p == 0)
  {
    ans += pow(2, cnt0);
    tmp = 0;
    for (int i = 0; i <= cnt1; i += 2)
    {
      tmp += a.C(cnt1, i);
    }
    cout << ans * tmp << endl;
  }
  else
  {
    tmp = 0;
    for (int i = 1; i <= cnt1; i += 2)
    {
      tmp += a.C(cnt1, i);
    }
    ans=tmp;
    tmp = 0;
    for (int i = 0; i <= cnt0; i++)
    {
      tmp += a.C(cnt0, i);
    }
    cout << ans * tmp << endl;
  }

  return 0;
}