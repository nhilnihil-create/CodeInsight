#include <bits/stdc++.h>
#define INF 1000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;


int main()
{
  ll N;
  cin >> N;
  unordered_map<ll, ll> odd;
  vector<ll> A(N);
  for (ll i = 0; i < N; ++i)
  {
    ll a;
    cin >> a;
    A.at(i) = a;
    if (i % 2 != 0)
    {
      odd[a] += 1;
    }
  }
  vector<ll> sort_A = A;
  sort(sort_A.begin(), sort_A.end());
  ll ans = 0;
  for (ll i = 0; i < N; ++i)
  {
    if (i % 2 == 0)
    {
      continue;
    }
    if (odd[sort_A.at(i)] == 0)
    {
      ans += 1;
    }
    else
    {
      odd[sort_A.at(i)] -= 1;
    }
  }
  cout << ans << endl;


  // for (ll i = 0; i < N; ++i)
  // {
  //   cout << A.at(i) << ' ';
  // }
  // cout << endl;
}
