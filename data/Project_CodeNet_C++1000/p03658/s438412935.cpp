#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;
int main()
{

  ll n,k,l[100];
  cin>>n>>k;
  rep(i,n)cin>>l[i];
  sort(l,l+n,greater<int>());
  ll ans=0;
  rep(i,k){
    ans+=l[i];
  }

  cout<<ans<<endl;
  return 0;
}
