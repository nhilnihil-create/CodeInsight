#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
  ll n;
  
  cin>>n;
  
  ll a[n];
  ll sum=0;
  for(int i=0;i<n;i++){
    cin>>a[i];
    sum+=a[i];
  }
  
  ll m;
  cin>>m;
  
  for(int i=0;i<m;i++){
    ll p,t;
    cin>>p>>t;
    cout<<sum-a[p-1]+t<<endl;
  }
  
  return 0;
}
