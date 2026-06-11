#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll w,h,n;
  cin >> w>> h >> n;
  vector<ll> x(n),y(n),a(n);
  ll u=h,d=0,l=0,r=w;
  rep(i,n){
    cin >> x.at(i) >> y.at(i) >> a.at(i);
  }
  rep(i,n){
    if(a.at(i)==1){
      l=max(l,x.at(i));
    }else if(a.at(i)==2){
      r=min(r,x.at(i));
    }else if(a.at(i)==3){
      d=max(d,y.at(i));
    }else{
      u=min(u,y.at(i));
    }
  }
  if(r-l>0 && u-d>0){
    cout << (r-l)*(u-d);
  }else{
    cout << 0;
  }
}
      
  