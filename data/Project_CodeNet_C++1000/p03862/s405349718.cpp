#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (ll i=0; i<(n); ++i)
typedef long long ll;
bool debug=false;
string yes = "Yes";
string no = "No";

int main(){
  ll n, x; cin >> n >> x;
  vector<ll> v(n, 0);
  ll ans = 0;
  rep(i,n){
    cin >> v[i];
    if(v[i]>x){
      ans += v[i]-x;
      v[i]=x;
    }
  }
  for(ll i=1; i<=n-1; i++){
    ll sum = v[i-1]+v[i];
    if(sum>x){
      ll dif = sum-x;
      if(dif<=v[i]){
        v[i]-=dif;
      }else{
        v[i-1]-=dif-v[i];
        v[i]-=v[i];
      }
      ans+=dif;
    }
  }
  cout << ans << endl;
  return 0;
}

