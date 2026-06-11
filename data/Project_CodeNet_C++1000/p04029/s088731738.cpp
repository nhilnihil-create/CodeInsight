#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;
int main()
{
  ll n,ans=0;
  cin>>n;
  rep(i,n){
    ans+=i+1;
  }
  cout<<ans<<endl;
  return 0;
}
