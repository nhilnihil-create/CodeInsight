#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, n) for (int i = (int)(n); i >= 0; i--)
#define REP(i, m, n) for (int i = (int)(m); i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long INF = 1LL << 60;

typedef pair<ll,ll> pii;
#define fi first
#define se second
#define mp make_pair

pii seph(int h, int w, int d){
  pii p = mp((ll)w*d, (ll)w*(h-d));
  return p;
}

pii sepw(int h, int w, int d){
  pii p = mp((ll)h*d, (ll)h*(w-d));
  return p;
}

ll dist(ll x, ll y, ll z){
  return max(x, max(y, z)) - min(x, min(y, z));
}

ll rec(int h, int w){
  pii p;
  ll s1, s2, s3;

  ll mi = INF;
  REP(i, 1, h-1){
    p = seph(h, w, i);
    s3 = p.se;

    s1 = (ll)w * (i/2);
    s2 = p.fi - s1;
    chmin(mi, dist(s1, s2, s3));

    s1 = (ll)i * (w/2);
    s2 = p.fi - s1;
    chmin(mi, dist(s1, s2, s3));
  }

  return mi;
}

int main(){
  int H, W;
  cin >> H >> W;
  
  cout << min(rec(H, W), rec(W, H)) << endl;

  return 0;
}
