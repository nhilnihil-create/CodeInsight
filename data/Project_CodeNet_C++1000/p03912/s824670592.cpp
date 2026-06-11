#include <iostream>
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_r(i, n) for (int i = n - 1; i >= 0; i--)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((ll)(x).size())
#define bit(n) (1LL << (n))
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());

#define INF bit(60)
#define pb push_back
#define mod 1000000007

using namespace std;
using uif = uint_fast64_t;
using ll = long long int;
using tTree = __gnu_pbds::tree<ll, __gnu_pbds::null_type, less<ll>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

ll dx[4] = {1, 0, -1, 0};
ll dy[4] = {0, 1, 0, -1};

#define FACSIZE 200002

ll invfac[FACSIZE];
ll fac[FACSIZE];

template <class T>
bool chmax(T &, const T &);
template <class T>
bool chmin(T &, const T &);
ll gcd(ll, ll);
ll powLL(ll x, ll y);

ll mod_pow(ll, ll);
ll mod_add(ll, ll);
ll mod_mul(ll, ll);
ll mod_div(ll, ll);
ll comb(ll, ll);
void make_fact(ll);
void make_invfact(ll);
void fact_init();

int main(void)
{
  ll n, m;
  cin >> n >> m;
  vector<ll> X(n);
  rep(i, n) cin >> X[i];

  if (m == 1)
  {
    cout << n / 2 << endl;
    return 0;
  }

  using pa = pair<ll, ll>;
  unordered_map<ll, ll> um[m];

  ll ans = 0;

  priority_queue<pa, vector<pa>, greater<pa>> pque[m];

  for (auto x : X)
  {
    um[x % m][x]++;
  }

  rep(i, m)
  {
    for (auto p : um[i])
    {
      //cout << p.first << "," << p.second << endl;
      if (p.second > 1 && p.second % 2 == 1)
      {
        pque[i].push(make_pair(1, p.first));
        pque[i].push(make_pair(p.second - 1, p.first));
      }
      else
        pque[i].push(make_pair(p.second, p.first));
    }
    //cout << endl;
  }
  for (ll i = 1; i <= (m - 1) / 2; i++)
  {
    auto m1 = i;
    auto m2 = m - i;
    while (!pque[m1].empty() && !pque[m2].empty())
    {
      auto pq1 = pque[m1].top();
      pque[m1].pop();
      auto pq2 = pque[m2].top();
      pque[m2].pop();
      //ll cnt = min(pq1.first, pq2.first);
      //ans += cnt;
      ll cnt = 1;
      ans++;
      if (pq1.first - cnt > 0)
      {
        pque[m1].push(make_pair(pq1.first - cnt, pq1.second));
      }
      if (pq2.first - cnt > 0)
      {
        pque[m2].push(make_pair(pq2.first - cnt, pq2.second));
      }
    }
    for (auto idx : {m1, m2})
    {
      while (!pque[idx].empty())
      {
        auto pq = pque[idx].top();
        pque[idx].pop();
        ll cnt = pq.first / 2;
        ans += cnt;
      }
    }
  }

  vector<ll> rest;
  rest.push_back(0);
  if (m % 2 == 0)
    rest.push_back(m / 2);
  for (auto idx : rest)
  {
    ll cnt = 0;
    while (!pque[idx].empty())
    {
      auto pq = pque[idx].top();
      pque[idx].pop();
      cnt += pq.first;
    }
    ans += cnt / 2;
  }

  cout << ans << endl;

  return 0;
}

ll mod_pow(ll x, ll r)
{
  if (r == 0)
    return 1;
  else if (r == 1)
    return x % mod;
  else if (r % 2 == 0)
  {
    ll t = mod_pow(x, r / 2) % mod;
    return mod_mul(t, t);
  }
  else
  {
    ll t = mod_pow(x, r / 2) % mod;
    ll k = mod_mul(t, t);
    return (k % mod) * (x % mod);
  }
}
ll mod_add(ll a, ll b)
{
  return ((a % mod) + (b % mod)) % mod;
}

ll mod_mul(ll a, ll b)
{
  return ((a % mod) * (b % mod)) % mod;
}

ll mod_div(ll a, ll b)
{
  return mod_mul(a, mod_pow(b, mod - 2));
}

void fact_init()
{
  make_fact(FACSIZE - 1);
  make_invfact(FACSIZE);
}

void make_fact(ll n)
{
  fac[0] = 1;
  rep(i, n)
  {
    fac[i + 1] = mod_mul(fac[i], i + 1);
  }
}

void make_invfact(ll n)
{
  invfac[n] = mod_pow(fac[n], mod - 2);
  for (int i = n - 1; i >= 0; i--)
  {
    invfac[i] = mod_mul(invfac[i + 1], i + 1);
  }
}

ll comb(ll n, ll r)
{

  return mod_mul(mod_mul(fac[n], invfac[r]), invfac[n - r]);
}
template <class T>
bool chmax(T &a, const T &b)
{
  if (a < b)
  {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
  if (b < a)
  {
    a = b;
    return 1;
  }
  return 0;
}

ll qp(ll a, ll b)
{
  ll ans = 1LL;
  do
  {
    if (b & 1LL)
      ans = 1LL * mod_mul(ans, a) % mod;
    a = 1LL * mod_mul(a, a) % mod;
  } while (b >>= 1LL);
  return ans;
}
ll qp(ll a, ll b, ll mo)
{
  ll ans = 1LL;
  do
  {
    if (b & 1LL)
      ans = 1LL * (ans % mo) * (a % mo);
    a = 1LL * (a % mo) * (a % mo);
  } while (b >>= 1LL);
  return ans;
}
ll gcd(ll a, ll b)
{
  return b ? gcd(b, a % b) : a;
}
ll powLL(ll x, ll y)
{
  ll ans = 1LL;
  for (ll i = 0LL; i < y; i++)
    ans *= x;
  return ans;
}
