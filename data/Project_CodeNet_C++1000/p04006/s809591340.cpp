#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using P = pair<ll,ll>;
using graph = vector<vector<int>>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = 1LL<<60;
const ll mod = 998244353LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template <typename T>
struct RMQ {//normal
    const T INF = numeric_limits<T>::max();
    int n;         
    vector<T> dat; 
    RMQ(int n_) : n(), dat(n_ * 4, INF) { 
        int x = 1;
        while (n_ > x) {
            x *= 2;
        }
        n = x;
    }
 
    void update(int i, T x) {
        i += n - 1;
        dat[i] = x;
        while (i > 0) {
            i = (i - 1) / 2;  
            dat[i] = min(dat[i * 2 + 1], dat[i * 2 + 2]);
        }
    }
 
    // the minimum element of [a,b)
    T query(int a, int b) { return query_sub(a, b, 0, 0, n); }
    T query_sub(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) {
            return INF;
        } else if (a <= l && r <= b) {
            return dat[k];
        } else {
            T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return min(vl, vr);
        }
    }
};

int main() {
  ll N,x;
  cin>>N>>x;
  vector<ll> v(N);
  rep(i,N) cin>>v[i];
  RMQ<ll> R(N);
  rep(i,N) {
    R.update(i,v[i]);
  }
  ll ans = INF;
  rep(i,N){
    ll p = 0;
    rep(j,N){
      int s = j-i;
      if(s<0) s += N;
      if(s>j){
        p += min(R.query(s,N),R.query(0,j+1));
      }
      else p += R.query(s,j+1);
    }
    p += x*i;
    chmin(ans,p);
  }
  cout<<ans<<endl;
}