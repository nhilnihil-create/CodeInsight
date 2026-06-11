#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int w,h,n; cin >> w >> h >> n;
  vector<int> x(n),y(n),a(n); rep(i,n) cin >> x[i] >> y[i] >> a[i];
  vector<vector<bool>> white(w,vector<bool>(h,true));
  
  rep(i,n){
    switch(a[i]){
    case 1:
      for(int j = 0;j<x[i];++j){
	  rep(k,h) white[j][k] = false;
      }
      break;
    case 2:
      for(int j = x[i];j<w;++j){
	  rep(k,h) white[j][k] = false;
      }
      break;
    case 3:
      rep(j,w){
	for(int k = 0;k<y[i];++k)
	   white[j][k] = false;
      }
      break;
    case 4:
      rep(j,w){
	for(int k = y[i];k<h;++k) white[j][k] = false;
      }
    }
  }
  int ans=0;

  rep(i,w){
    rep(j,h){
      if(white[i][j]){
	ans++;
      }
    }
  }  
  
  cout << ans << endl;
  
  return 0;
}
