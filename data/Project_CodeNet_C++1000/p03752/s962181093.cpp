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

template<typename T1 = long long, typename T2 = long long>
void recursive_comb(vector<T2> indexes, T1 s, T1 rest, std::function<void(vector<T2>)> func) {
  if(rest==0) {
    func(indexes);
  }
  else {
    if (s < 0) return;
    recursive_comb(indexes, s-1, rest, func);
    indexes[rest-1] = s;
    recursive_comb(indexes, s-1, rest-1, func);
  }
}
template<typename T1 = long long, typename T2 = long long>
void foreach_comb(T1 n, T1 k, std::function<void(vector<ll>)> func) {
  vector<ll> indexes(k);
  recursive_comb(indexes, n-1, k, func);
}

int main() {
  cin >> N >> K;
  a.resize(N);
  rep(i,N) cin >> a[i];
  
  // vector<ll> ind(K);
  // recursive_comb(ind, N-1, K);
  foreach_comb(N, K, [&](vector<ll> ind) {
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
  });
  cout << ans << endl;
  return 0;
}
