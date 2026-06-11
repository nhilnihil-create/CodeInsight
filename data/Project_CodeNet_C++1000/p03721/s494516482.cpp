#include <bits/stdc++.h>
#define vsort(v) sort(v.begin(), v.end())
#define rvsort(v) sort(v.begin(), v.end(), greater<ll>())
#define ll long long
#define rep(i, s, g) for (ll i = (s); i < (g); i++)
#define MOD 1000000007
#define vfind(v, target) find(v.begin(), v.end(), target)
#define notFound(v, target) (vfind(v, target) == v.end())

using namespace std;

int main()
{
  ll N, K; cin >> N >> K;
  vector<pair<ll, ll>> AB(N);
  rep(i, 0, N) {
  	ll a, b; cin >> a >> b;
    AB[i] = make_pair(a, b);
  }
  vsort(AB);
  rep(i, 0, N) {
  	if (AB[i].second >= K) {
    	cout << AB[i].first << endl;
      	return 0;
    } else {
    	K -= AB[i].second;
    }
  }
}