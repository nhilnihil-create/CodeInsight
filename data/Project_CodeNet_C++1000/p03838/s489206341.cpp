#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define all(A) A.begin(),A.end()
typedef long long ll;

int main(){
  
  ll x,y;
  cin >> x >> y;
  int ans = 0;
  if(x*y==0){
    if(x<y) ans = y-x;
    if(y<x) ans = x-y+1;
  }
  if(x*y>0){
    if(x<y) ans = y-x;
    if(y<x) ans = x-y+2;
  }
  if(x*y<0){
    ans = abs(x+y)+1;
  }
  cout << ans << endl;
}
