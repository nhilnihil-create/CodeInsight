#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int n;
  ll x;
  cin>>n>>x;
  ll vec[n],ans=0,zero=0;
  for(int i=0;i<n;i++){
    cin>>vec[i];
  }
  for(int i=0;i<n-2;i++){
    if(vec[i]+vec[i+1]<=x){
      continue;
    }
    if(vec[i]<=x){
      ans+=vec[i+1]-(x-vec[i]);
      vec[i+1]=x-vec[i];
      continue;
    }
    ans+=vec[i+1];
    vec[i+1]=0;
    ans+=vec[i]-x;
    vec[i]=x;
  }
  cout<<ans+max(zero,vec[n-2]+vec[n-1]-x)<<endl;
}