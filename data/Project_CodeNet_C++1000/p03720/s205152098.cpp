#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll N,M;
  cin>>N>>M;
  vector<ll> vec(N,0);
  for(ll i=0;i<M;i++) {
ll a,b;
    cin>>a>>b;
    vec[a-1]++;
    vec[b-1]++;
  }
  for(ll x:vec) {
cout<<x<<endl;
  }
}
