#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll n,m,ans=0; cin>>n>>m;
  if(2*n<=m) {
    m -= 2*n;
    ans += n;
    ans += m/4;
  }
  else {
    ans += m/2;
  }
  cout<<ans;
}