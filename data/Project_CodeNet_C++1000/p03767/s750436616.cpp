#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main() {
  ll n; cin>>n;
  vector<ll> v(3*n);
  rep(i,3*n){cin>>v[i];}
  sort(v.begin(),v.end());
  ll ans=0,i=n;
  while(i<3*n-1){
    ans+=v[i];//cout<<i;
    i+=2;
  }
  cout<<ans<<endl;
} 