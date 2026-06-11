#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  long long x,ans=0,cnt=1,y;
  cin >> x;
  y=x*2;
  ans=y/11;
  if(x%11>0&&x%11<6){
    ans++;
  }
  if(x%11>6){
    ans++;
  }
  cout << ans;
}