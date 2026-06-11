#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<cmath>
#include<climits>
#include<queue>
#include<stack>
#include<numeric>
#include<set>
#include<iomanip>
#include<map>
#include<type_traits>
#include<tuple>
#include<deque>
#include<cassert>
#include<bitset>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
const int mod = 1000000007;
const ll INF = ll(1e18) + 1;

int main() {
  ll n, W;
  cin >> n >> W;
  vector<ll> w(n);
  vector<ll> v(n);
  vector<vector<ll>> bag(4);
  rep(i, n) {
    cin >> w[i] >> v[i];
  }

  ll base = w[0];
  rep(i, n) {
    ll weight = w[i] - base;
    bag[weight].push_back(v[i]);
  }

  ll ans = 0;
  rep(i, 4) {
    sort(bag[i].rbegin(), bag[i].rend());
    bag[i].insert(bag[i].begin(), 0);
  }

  ll cur1 = 0;
  rep(i, bag[0].size()) {
    cur1 += bag[0][i];
    ll cur2 = 0;
    rep(j, bag[1].size()) {
      cur2  += bag[1][j];
      ll cur3 = 0;
      rep(k, bag[2].size()) {
        cur3 += bag[2][k];
        ll cur4 = 0;
        rep(l, bag[3].size()) {
          cur4 += bag[3][l];
          ll value = cur1 + cur2 + cur3 + cur4;
          ll weight = i * base + (1 + base) * j + (2 + base) * k + (3 + base) * l;
          if(weight > W) continue;
          ans = max(ans, value);
        }
      }
    }
  }
  cout << ans << endl;
}