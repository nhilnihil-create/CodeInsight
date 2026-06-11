#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;
int main()
{

  ll n,T;
  ll t[200010];
  cin>>n>>T;
  rep(i,n)cin>>t[i];

  ll ans=0;


  reps(i,n){
    if(t[i]-t[i-1]>=T){
      ans+=T;
    }else{
      ans+=t[i]-t[i-1];
    }
  }
  ans+=T;
  cout<<ans<<endl;
  return 0;
}
