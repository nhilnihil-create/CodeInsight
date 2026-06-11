#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;
int main()
{

  ll a,b;
  cin>>a>>b;
  ll ans=a+b;
  if(ans>=24)ans-=24;
  cout<<ans<<endl;
  return 0;
}
