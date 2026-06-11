#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using lb = long double;
using P = pair<ll,ll>;
using graph = vector<vector<ll>>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = 1LL<<60;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll N;
  cin>>N;
  vector<ll> v(N);
  rep(i,N) cin>>v[i];
  vector<ll> d(N);
  rep(i,N) {
    if(i==0) d[i] = v[i];
    else d[i] = v[i]-v[i-1];
  }
  vector<ll> s(N);
  rep(i,N) s[i] = i;
  ll M,K;
  cin>>M>>K;
  rep(i,M){
    ll a;
    cin>>a;
    a--;
    swap(s[a],s[a+1]);
  }
  vector<vector<ll>> db(61,vector<ll>(N));
  rep(i,61){
    if(i==0) db[i] = s;
    else {
      rep(j,N){
        db[i][j] = db[i-1][db[i-1][j]];
      }
    }
  }
  vector<ll> ans(N);
  rep(i,N) ans[i] = i;
  rep(i,61){
    if(K&(1LL<<i)){
      rep(j,N){
        ans[j] = db[i][ans[j]];
      }
    }
  }
  ll p = 0;
  rep(i,N){
    p+=d[ans[i]];
    cout<<p<<endl;
  }
}