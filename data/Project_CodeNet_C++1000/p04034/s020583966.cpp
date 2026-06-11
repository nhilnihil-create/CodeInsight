#include <bits/stdc++.h>
#define vsort(v) sort(v.begin(), v.end())
#define rvsort(v) sort(v.begin(), v.end(), greater<ll>())
#define ll long long
#define rep(i, s, g) for (ll i = (s); i < (g); i++)
#define mod 1000000007
#define vfind(v, target) find(v.begin(), v.end(), target)
#define notFound(v, target) (vfind(v, target) == v.end())

using namespace std;

int main()
{
  ll N, M; cin >> N >> M;
  vector<ll> num(N, 1);
  vector<bool> red(N, false);
  red[0] = true;
  rep(i, 0, M) {
  	ll x, y; cin >> x >> y;
    x--; y--;
    if (red[x]) {
    	red[y] = true;
    }
    num[x]--; num[y]++;
    if (num[x] == 0) {
    	red[x] = false;
    }
  }
  ll ans = 0;
  rep(i, 0, N) {
  	if (red[i]) ans++;
  }
  cout << ans << endl;
}