#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int
#define INF 1000000007
int main(){
int n,m;
cin>>n>>m;
if(abs(n-m)>1){
  cout<<0<<endl;
  return 0;
}
if(n==m){
  ll ans=1;
  while(n>0){
ans=(ans*n)%1000000007;
n--;
//cout<<ans<<endl;
  }
ans=(((ans*ans)%INF)*2)%1000000007;
cout<<ans<<endl;
return 0;
}else
{
  n=min(n,m);
  int A=n;
   ll ans=1;
  while(n>0){
ans=(ans*n)%1000000007;
n--;
  }
ans=(((ans*ans)%INF)*(A+1))%1000000007;
cout<<ans<<endl;
return 0;
}


  return 0;
}
