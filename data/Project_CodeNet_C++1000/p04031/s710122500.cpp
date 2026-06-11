#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;
int main()
{

  ll n,a[110],ans=1LL<<60;
  cin>>n;
  rep(i,n){
    cin>>a[i];
  }

  for(ll m=-100;m<=100;m++){
    ll tmp=0;
    rep(i,n){
      tmp+=(a[i]-m)*(a[i]-m);
    }
    ans=min(ans,tmp);
  }


  cout<<ans<<endl;
  return 0;
}
