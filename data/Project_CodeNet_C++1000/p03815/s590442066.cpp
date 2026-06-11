#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll x;
  cin >> x;
  ll q=x%11;
  ll p=x/11;
  ll ans=2*p;
  if(q>0 && q<=6){
    ans++;
  }else if(q>0 &&q<=12){
    ans+=2;
  }
  cout << ans;
}
      