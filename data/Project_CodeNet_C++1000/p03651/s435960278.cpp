#include<bits/stdc++.h>
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1000000007;
const int INF = 1001001001;

ll gcd(ll a, ll b) { return (b == 0) ? a : gcd(b, a % b); }

int main() {
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  ll maxv = 0;
  rep(i, n) {
    cin >> a[i];
    chmax(maxv, a[i]);
  }

  
  ll g = a[0];
  rep(i, n) {
    g = gcd(g, a[i]);
  }

  if (k % g || maxv < k) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    cout << "POSSIBLE" << endl;
  }

}