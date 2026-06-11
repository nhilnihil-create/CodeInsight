#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int

int main(){
ll n,m;
cin>>n>>m;
ll ans=0;
if(2*n<=m){
ans+=n;
m-=2*n;
ans+=m/4;
}else
{
  ans+=m/2;
}


cout<<ans<<endl;
  return 0;
}
