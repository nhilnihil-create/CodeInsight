#include<bits/stdc++.h>
#define rep(i,n)  for(ll i = 0; i < n; i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF 1e9
using ll = long long;
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(b<a) { a=b; return 1; } return 0; }

int main(){
  int w,h,n; cin >> w >> h >> n;
  vi x(n),y(n),a(n); rep(i,n) cin >> x[i] >> y[i] >> a[i];
  vector<vi> white(h,vi(w,1));

  rep(i,n){
    if(a[i] == 1) rep(j,h) rep(k,x[i]) white[j][k] = 0;
    else if(a[i] == 2) rep(j,h) for(int k = x[i]; k < w; k++) white[j][k] = 0;
    else if(a[i] == 3) rep(j,y[i]) rep(k,w) white[j][k] = 0;
    else if(a[i] == 4) for(int j = y[i]; j < h; j++) rep(k,w) white[j][k] = 0;
  }
  int ans = 0;
  rep(i,h) ans += accumulate(all(white[i]),0);
  cout << ans;
  cout << "\n";
  return 0;
}
