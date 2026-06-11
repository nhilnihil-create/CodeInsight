#include <bits/stdc++.h>
#define INF 1000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main()
{
  ll mod = 1000000007;
  ll N;
  cin >> N;
  vector<ll> T(N);
  vector<ll> A(N);
  for (ll i = 0; i < N; ++i)
  {
    cin >> T.at(i);
  }
  for (ll i = 0; i < N; ++i)
  {
    cin >> A.at(i);
  }
  vector<ll> low(N);
  for (ll i = 0; i < N; ++i)
  {
    low.at(i) = min(A.at(i), T.at(i));
  }
  vector<bool> revealed(N, false);
  revealed.at(0) = true;
  if (A.at(0) < T.at(0))
  {
    cout << 0 << endl;
    return 0;
  }
  for (ll i = 1; i < N; ++i)
  {
    if (T.at(i) != T.at(i - 1))
    {
      if (A.at(i) < T.at(i))
      {
        cout << 0 << endl;
        return 0;
      }
      revealed.at(i) = true;
    }
  }

  revealed.at(N - 1) = true;
  if (T.at(N - 1) < A.at(N - 1))
  {
    cout << 0 << endl;
    return 0;
  }
  for (ll i = N - 2; i >= 0; --i)
  {
    if (A.at(i) != A.at(i + 1))
    {
      if (T.at(i) < A.at(i))
      {
        cout << 0 << endl;
        return 0;
      }
      revealed.at(i) = true;
    }
  }

  ll ans = 1;
  for (ll i = 0; i < N; ++i)
  {
    if (revealed.at(i))
    {
      continue;
    }
    ans = (ans * low.at(i)) % mod;
  }
  cout << ans << endl;

}
