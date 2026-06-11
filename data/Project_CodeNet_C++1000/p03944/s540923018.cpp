#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main() {
 int w,h,n; cin >> w >> h >> n;
 int wlef=0,hbot=0,wrig=w,htop=h;
  rep(i,n){
    int x,y,a; cin >> x >> y >> a;
    if(a==1 && wlef<=x)wlef=x;

    else if(a==2 && wrig>=x)wrig=x;

    else if(a==3 && hbot<=y)hbot=y;

    else if(a==4 && htop>=y)htop=y;
  }
 int ans=(max(0,wrig-wlef))*(max(0,htop-hbot));
  cout << ans << endl;
}
