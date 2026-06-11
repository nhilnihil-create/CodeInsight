#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(obj) (obj).begin(), (obj).end()
#define bit(n) (1LL << (n))

typedef long long ll;

template<class T> inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const long long INF = 1LL << 60;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n,m; cin>>n>>m;
  
  vector<pair<int,int>> st(n);
  vector<int> point(n);
  
  vector<pair<int,int>> ch(m);
  
  rep(i,n) {
    ll a,b; cin>>a>>b;
    pair<ll, ll> p;
    p = make_pair(a, b);
    st[i] = p;
  }
   
  rep(i,m) {
    ll c,d; cin>>c>>d;
    pair<ll, ll> p;
    p = make_pair(c, d);
    ch[i] = p;
  }
  
  rep(i,n) {
    pair<ll, ll> stp = st[i];
    ll mandiss = 10000000000;
    int dissnum = 100;
    rep(j,m) {
      pair<ll, ll> chp = ch[j];
      ll dis = abs(stp.first - chp.first) + abs(stp.second - chp.second);
      if (dis<mandiss) {
        mandiss = dis;
        dissnum = j+1;
      }
    }
    point[i] = dissnum;
  }
  
  rep(i,n) {
    cout<<point[i]<<endl;
  }
}