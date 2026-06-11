#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(){
  int n,a,b;
  cin>>n>>a>>b;
  ll x[100005];
  rep(i,n) cin>>x[i];
  ll ans=0;
  rep(i,n-1){
    if((x[i+1]-x[i])*a>b) ans+=b;
    else ans+=(x[i+1]-x[i])*a;
  }
  cout<<ans<<endl;
  return 0;
}