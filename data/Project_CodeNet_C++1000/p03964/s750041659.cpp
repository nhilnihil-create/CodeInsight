#include<bits/stdc++.h>
using namespace std;
using ll=long long;
 
int main(){
  ll i,j,cnt;
  int n;
  ll t=1,a=1;
  cin>>n;
  ll T[n],A[n];
  for(i=0;i<n;i++)cin>>T[i]>>A[i];
  for(i=0;i<n;i++){
    j=max((t+T[i]-1)/T[i],(a+A[i]-1)/A[i]);
    while(a>A[i]*j || t>T[i]*j)j++;
    t=j*T[i];
    a=j*A[i];
  }
  cout<<t+a;
}