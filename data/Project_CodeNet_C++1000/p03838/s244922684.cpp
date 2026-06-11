#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  ll x,y;
  cin >> x >> y;

  if(x*y>=0&&x<=y) cout << y-x;
  else if(x*y>0&&x>y) cout << x-y+2;
  else cout << abs(abs(x)-abs(y))+1;
}