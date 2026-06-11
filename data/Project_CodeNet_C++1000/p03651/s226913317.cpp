#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define SORT(v) sort(v.begin(), v.end());
#define RSORT(v) sort(v.rbegin(), v.rend());
#define REVERSE(v) reverse(v.begin(), v.end());
typedef long long ll;
ll gcd(ll a, ll b)
{
  return b ? gcd(b, a % b) : a;
}

int main()
{
  int N, K;
  cin >> N >> K;
  ll all_gcd = 1;
  ll maxA = 0;
  vector<ll> A(N);
  rep(i, N)
  {
    cin >> A[i];
    all_gcd = A[i];
    maxA = max(maxA, A[i]);
  }
  rep(i, N)
  {
    all_gcd = gcd(all_gcd, A[i]);
  }
  if (K % all_gcd == 0 && K <= maxA)
    cout << "POSSIBLE" << endl;
  else
    cout << "IMPOSSIBLE" << endl;
  return 0;
}