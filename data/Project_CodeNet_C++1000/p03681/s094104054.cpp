#include<iostream>
#include<algorithm>
using namespace std;
int main(void)
{ 
long long int n,m,a,mod;
  mod=1000000000+7;
  int i;
  cin>>n>>m;
  a=1;
  if(n-m>1||n-m<-1){cout<<0;return 0;}
  for(i=1;i<=n;i++){a=a*i;a=a%mod;}
  for(i=1;i<=m;i++){a=a*i;a=a%mod;}
  if(n==m)a=2*a;
  a=a%mod;
  cout<<a;
  
}