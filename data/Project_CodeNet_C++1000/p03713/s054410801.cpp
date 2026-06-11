#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  ll h,w;
  ll ans = 1e10+1;
  cin >> h >> w;
  rep(x,1,h){
    ll m,M;
    m = min(x*w,(h-x)*(w/2));
    M = max(x*w,(h-x)*((w+1)/2));
    ans = min(ans,M-m);
    m = min(x*w,((h-x)/2)*w);
    M = max(x*w,((h-x+1)/2)*w);
    ans = min(ans,M-m);
  }
  rep(y,1,w){
    ll m,M;
    m = min(y*h,(w-y)*(h/2));
    M = max(y*h,(w-y)*((h+1)/2));
    ans = min(ans,M-m);
    m = min(y*h,((w-y)/2)*h);
    M = max(y*h,((w-y+1)/2)*h);
    ans = min(ans,M-m);
  }
  cout << ans << endl;
}