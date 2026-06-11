#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=1e9+7;
ll n;
ll x[100005];


ll mul(ll a,ll b){
  return (a*b)%mod;
}

int main(){
  
  cin>>n;
  for(int i=0;i<n;i++)cin>>x[i];
  
  if(n==2){
    cout<<2<<endl;
    return 0;
  }

  vector<ll> v;
  ll c=1,f=1;
  for(ll i=0;i<n;i++){
    if(x[i]<c){
      v.push_back(i+1);
    }else{
      c+=2;
    }
  }

  ll num=c/2;
  //  cout<<num<<endl;

  for(ll i=0;i<(int)v.size();i++){
    f=mul(f,v[i]-i);
  }
  
  for(ll i=1;i<=num;i++){
    f=mul(f,i);
  }

  cout<<f<<endl;
  return 0;
}

