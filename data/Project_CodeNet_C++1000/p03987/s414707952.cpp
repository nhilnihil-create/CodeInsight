#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define speed                   \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
#define ll long long
#define pb push_back
#define endl "\n"
#define mod 1000000007
#define ff first
#define ss second
#define inf 1e18
#define N 5000005
#define all(v) v.begin(), v.end()
#define sbit(a) __builtin_popcount(a)
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> ppl;
typedef map<ll, ll> mpll;
typedef map<vector<ll>, ll> mpvl;
// vector<ll> par, rnk, dep;
// vector<vector<ll>> adj;
// vector<ll> ance;
// vector<ll> vis;
// ll sp[N][26], bp[N][20];
ll power(ll x, ll y, ll p)
{
  ll res = 1;

  x = x % p;

  if (x == 0)
    return 0;
  while (y > 0)
  {

    if (y & 1)
      res = (res * x) % p;

    y = y >> 1;
    x = (x * x) % p;
  }

  return res;
}
void spt(ll n, ll arr[], ll sp[N][26])
{
  for (ll i = 0; i < n; i++)
    sp[i][0] = arr[i];
  for (ll j = 1; j <= 25; j++)
  {
    for (ll i = 0; i + (1 << j) <= n; i++)
    {
      sp[i][j] = min(sp[i][j - 1], sp[i + (1 << (j - 1))][j - 1]);
    }
  }
}
void solve()
{

  ll n;
  cin >> n;
  vector<ll> arr(n, 0);
  for (ll i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  stack<ll> st;
  ll L[n], R[n];
  fill(L, L + n, -1);
  fill(R, R + n,n);
  for (ll i = 0; i < n; i++)
  {
    while (!st.empty() && arr[st.top()] > arr[i])
    {
      st.pop();
    }
    if (!st.empty())
      L[i] = st.top();
    st.push(i);
  }
  while (!st.empty())
    st.pop();

  for (ll i = n - 1; i >= 0; i--)
  {
    while (!st.empty() && arr[st.top()] >= arr[i])
    {

      st.pop();
    }
    if (!st.empty())
      R[i] = st.top();
    st.push(i);
  }
  ll ansmin[n];
  ll sumin=0,sumax=0;
  for(ll i=0;i<n;i++)
  {
    ansmin[i]=(i-L[i])*(R[i]-i)*arr[i];
    sumin+=ansmin[i];
  }
  cout<<sumin<<endl;
  //  while (!st.empty())
  //   st.pop();
  // fill(L, L + n, -1);
  // fill(R, R + n,n);
  // for (ll i = 0; i < n; i++)
  // {
  //   while (!st.empty() && arr[st.top()]<arr[i])
  //   {
  //     st.pop();
  //   }
  //   if (!st.empty())
  //     L[i] = st.top();
  //   st.push(i);
  // }
  // while (!st.empty())
  //   st.pop();

  // for (ll i = n - 1; i >= 0; i--)
  // {
  //   while (!st.empty() && arr[st.top()] <= arr[i])
  //   {

  //     st.pop();
  //   }
  //   if (!st.empty())
  //     R[i] = st.top();
  //   st.push(i);
  // }
  // ll ansmax[n];
  // for(ll i=0;i<n;i++)
  // {
  //   ansmax[i]=(i-L[i])*(R[i]-i)*arr[i];
  //   sumax+=ansmax[i];
  // }
  // cout<<sumax-sumin<<endl;
 
 

}

int main()
{

  speed;
  ll t;
  t = 1;
  // cin >> t;
  while (t--)
  {

    solve();
  }
}
