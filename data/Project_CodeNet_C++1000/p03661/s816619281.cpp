#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  ll n,a,m=1000000000000000000;
  cin>>n>>a;
  ll dp[n];
  dp[0]=a;
  for(int i=1;i<n;i++){
    cin>>a;
    dp[i]=dp[i-1]+a;
  }
  for(int i=0;i<n-1;i++){
    m=min(m,abs((dp[n-1]-dp[i])-dp[i]));
  }
  cout<<m;
}