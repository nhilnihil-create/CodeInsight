#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD=1000000007;


int main() {
  ll K,T;
  cin>>K>>T;
  vector<ll> a(K);
  for(int i=0;i<K;i++){
    cin>>a[i];
  }
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
  if(2*a[0]-K-1<0){
    cout<<0;
  }
  else{
    cout<<2*a[0]-K-1;
  }
  
}