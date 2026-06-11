#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
ll mod= 1e9 + 7;



int main() {
  int w,h,n;
  cin >> w >>h >>n;
  int lx=0,rx=w,ly=0,ry=h;
  rep(i,n){
    int x,y,a;
    cin >>x >>y >>a;
    if(a==1){lx=max(lx,x);}
    if(a==2){rx=min(rx,x);}
    if(a==3){ly=max(ly,y);}
    if(a==4){ry=min(ry,y);}
  }
  if(rx<=lx || ry<=ly){cout << 0 << endl;}else{cout << (rx-lx)*(ry-ly) << endl;}
}