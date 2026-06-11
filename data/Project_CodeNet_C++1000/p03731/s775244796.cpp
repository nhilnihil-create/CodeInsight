#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,T;cin>>n>>T;
  int t[n],x=T;
  for(int i=0;i<n;i++){
    cin>>t[i];
    if(i==0)continue;
    if(T<=t[i]-t[i-1])x+=T;
    else x+=t[i]-t[i-1];    
  }
  cout<<x;
}