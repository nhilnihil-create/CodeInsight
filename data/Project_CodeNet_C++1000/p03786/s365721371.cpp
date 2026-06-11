#include <bits/stdc++.h>  
using namespace std;
#define rep(i,n) for(ll i=0; i<(ll)(n); i++)
using ll = long long int;

int main() {
  int  n; cin>>n;
  vector<ll> v(n);
  rep(i,n){
    cin>>v[i];
  }
  sort(v.begin(),v.end() );
  rep(i,n-1){
    v[i+1]+= v[i];
  }
  int  c=1;
  rep(i,n-1){
    if(v[n-1-i]<=3*v[n-2-i]){c++;}
    else{break;}
  }
  cout<<c<<endl;
}