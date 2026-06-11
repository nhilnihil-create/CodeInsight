#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define INF 1999999999
#define MODA 1000000007 
#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

ll N, K;
vector<ll> a;
ll ans = std::numeric_limits<ll>::max();

void recursive_comb(vector<ll> ind, int s, int rest) {
  // cerr << s << endl;
  if(rest==0) {
    ll cost = 0;
    vector<ll> builds = a;
    ll cind = 0;
    ll high = 0;
    for (ll i=0; i<N; ++i) {
      if(i == ind[cind]) {
        if(builds[i] > high) {
          high = builds[i];
        }
        else {
          high += 1;
          cost += high - builds[i];
          builds[i] = high;
        }
        cind++;
      }
      else {
        high = max(builds[i], high);
      }
    }
    ans = min(cost,ans);
  }
  else {
    if (s < 0) return;
    recursive_comb(ind, s-1, rest);
    ind[rest-1] = s;
    recursive_comb(ind, s-1, rest-1);
  }
}

int main() {
  cin >> N >> K;
  a.resize(N);
  rep(i,N) cin >> a[i];

  vector<ll> ind(K);
  recursive_comb(ind, N-1, K);
  cout << ans << endl;
  return 0;
}
