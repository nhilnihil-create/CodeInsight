#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
using pii = pair<int, int>;

ll LCM(ll x, ll y){
  if(x<y){swap(x,y);}
  ll i=1;
  while(true){
    if((x*i)%y==0){
      return x*i;
    }
    i++;
  }
}
int main() {
  int n; cin>>n;
  vector<ll> v(n);
  rep(i,n){
    cin>>v[i];
  }
  ll ans=v[0];
  rep(i,n){ans=LCM(ans,v[i]);}
  cout<<ans;
}