#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll a,b,c,ans=0;
  cin>>a>>b>>c;
  if(a%2==1 || b%2==1 || c%2==1){
    cout<<0<<endl;
    return 0;
  }
  if(a==b&&b==c){
    cout<<-1<<endl;
    return 0;
  }
  while(true){
    ans++;
    ll x,y,z;
    x=b/2+c/2;
    y=a/2+c/2;
    z=a/2+b/2;
    a=x;b=y;c=z;
    if(a%2==1 || b%2==1 || c%2==1){
      break;
    }
  }
  cout<<ans<<endl;
}