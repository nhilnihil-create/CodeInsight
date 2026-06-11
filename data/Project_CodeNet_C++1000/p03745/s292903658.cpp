#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main() {
  ll n; cin>>n;
  vector<ll> v(n);
  rep(i,n){cin>>v[i];}
  
  ll c=1;
  ll i=0;
  while(i<n-1){
    if(v[i]<v[i+1]){
      while(i<n-1){
        if(v[i]>v[i+1]){c++; i++; break;}
        i++;
      }
    }
    else if(v[i]>v[i+1]){
      while(i<n-1){
        if(v[i]<v[i+1]){c++; i++; break;}
        i++;
      }
    }
    else  if(v[i]==v[i+1]){i++;}
  }
  cout<<c;
} 