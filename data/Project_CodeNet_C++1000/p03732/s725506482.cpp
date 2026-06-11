#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair <double,double> P;

int main() {
  int N,W;
  cin>>N>>W;
  vector<ll> vec[4];
  ll w0;
  rep(i,N) {
    ll w,v;
    cin>>w>>v;
    if (i==0) w0=w;
    vec[w-w0].push_back(v);
  }
  rep(i,4) {
    sort(vec[i].begin(),vec[i].end());
    reverse(vec[i].begin(),vec[i].end());
  }
  vector<ll> sum[4];
  rep(i,4) {
    ll add=0;
    sum[i].push_back(0);
    rep(j,vec[i].size()) {
      add+=vec[i][j];
      sum[i].push_back(add);
    }
  }
  ll ans=0;
  rep(i,sum[0].size()) {
    rep(j,sum[1].size()) {
      rep(k,sum[2].size()) {
	rep(l,sum[3].size()) {
	  if (w0*i+(w0+1)*j+(w0+2)*k+(w0+3)*l>W) break;
	  ans=max(ans,sum[0][i]+sum[1][j]+sum[2][k]+sum[3][l]);
	}
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}