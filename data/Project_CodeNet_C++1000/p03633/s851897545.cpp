#include<bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin>>n;
  long long t[105],u=0;
  for(int i=0;i<n;i++){
    cin>>t[i];
  }
  if(n!=1){
  for(int i=1;i<n;i++){
    if(i==1){
    u=t[i]/__gcd(t[i],t[i-1])*t[i-1];
    }else{
      u=u/__gcd(u,t[i])*t[i];
    }
  }
  if(u<=1000000000000000000){
  cout<<u<<"\n";
  }else{
    cout<<1000000000000000000<<"\n";
  }
  }else{
    cout<<t[0]<<"\n";
  }
  return 0;
}