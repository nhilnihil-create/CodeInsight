#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,a,b) for(int i=(a);i<(b);++i)

template<class T> inline void chmin(T& a, T b) {if (a > b) a = b;}
template<class T> inline void chmax(T& a, T b) {if (a < b) a = b;}

//vector出力
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){
  o<<"{";
  for(int i=0;i<(int)v.size();i++) o << (i>0?", ":"") << v[i];
  o<<"}"<<endl;
  return o;
}


int main() {
  ll N,W,w,v,w1;
  cin >> N >> W;
  vector<vector<ll>> V(4);
  rep(i,N) {
    cin >> w >> v;
    if (i==0) w1=w;
    V[w-w1].push_back(v);
  }
  rep(i,4) sort(V[i].rbegin(),V[i].rend());
  rep(i,4){
    rep(j,V[i].size()) {
      if (j==0) continue;
      V[i][j]+=V[i][j-1];
    }
  }
  ll res = 0;
  rep(i,V[0].size()+1) {
    rep(j,V[1].size()+1) {
      rep(k,V[2].size()+1) {
        rep(l,V[3].size()+1) {
          if (w1*(i+j+k+l)+j+2*k+3*l>W) continue;
          ll tmp=0;
          if (i>0) tmp += V[0][i-1];
          if (j>0) tmp += V[1][j-1];
          if (k>0) tmp += V[2][k-1];
          if (l>0) tmp += V[3][l-1];
          chmax(res,tmp);
        }
      }
    }
  }
  cout << res << endl;
}