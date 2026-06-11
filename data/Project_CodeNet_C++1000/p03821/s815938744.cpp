#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define reps(i,a,b) for(int i= a; i < b; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int n;
  cin >> n;
  vector<ll> A(n), B(n);
  rep(i, n) {
    cin >> A.at(i) >> B.at(i);
  }
  ll cnt = 0;
  ll ans = 0;
  repr(i, n-1) {
    A.at(i) += cnt;
    if (A.at(i) % B.at(i) == 0) continue;

    ll v =  B.at(i) - (A.at(i) % B.at(i));
    ans += v;
    cnt += v;
  }
  cout << ans << endl;
  return 0;
}