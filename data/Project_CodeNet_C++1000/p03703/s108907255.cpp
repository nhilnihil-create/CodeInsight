#include <bits/stdc++.h>
#define DUMP(x)  cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define IFOR(i, m, n) for(int i = n - 1; i >= m; i-- )
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define FOREACH(x,a) for(auto& (x) : (a) )
#define ALL(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
const ll INF = LLONG_MAX;
/* テンプレートここまで */
//1-indexed
class BIT {
public:
  vector<ll> bit;
  ll M;

  BIT(ll M):
    bit(vector<ll>(M+1, 0)), M(M) {}

  //a[1] + a[2] + ... + a[i]を求める
  ll sum(ll i) {
    if (i==0) return 0;
    return bit[i] + sum(i-(i&-i));
  }
  //a[i] += x
  void add(ll i, ll x) {
    if (i > M) return;
    bit[i] += x;
    add(i+(i&-i), x);
  }
};

int main() {
  ll N, K; cin >> N >> K;
  vector<ll> sum(N+1, 0);
  REP(i, N) {
    ll a;
    cin >> a;
    a -= K;
    sum[i+1] = sum[i] + a;
  }

  vector<ll> vals;
  REP(i, N+1) vals.push_back(sum[i]);
  sort(ALL(vals));
  vals.erase(unique(ALL(vals)), vals.end());

  REP(i, N+1){
    ll idx = lower_bound(ALL(vals), sum[i]) - vals.begin();
    sum[i] = idx+1;
  }

  BIT b(N+1);
  ll ans = 0;
  REP(i, N+1){
    ans += b.sum(sum[i]);
    b.add(sum[i], 1);
  }
  cout << ans << endl;
}
