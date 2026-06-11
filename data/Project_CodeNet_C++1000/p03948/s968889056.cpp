#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n,t;cin>>n>>t;
  ll a[n];
  for(ll i=0;i<n;i++)cin>>a[i];
  ll sam=0;
  ll kam=0;
  map<ll,ll>mp;
  for(ll i=n-1;i>=0;i--){
    if(a[i]>kam){
      kam=a[i];
      continue;
    }
    mp[kam-a[i]]++;
    sam=max(sam,kam-a[i]);
  }
  cout<<mp[sam]<<endl;
}