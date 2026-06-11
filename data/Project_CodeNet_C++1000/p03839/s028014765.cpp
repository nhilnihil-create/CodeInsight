#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007


int main(){
  
  int n,k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i,n)cin >> a[i];
  vector<ll> ps(n+1,0),s(n+1,0);
  rep(i,n){
    s[i+1] = s[i]+a[i];
    if(a[i] > 0)ps[i+1] = ps[i]+a[i];
    else ps[i+1] = ps[i];
  }
  ll res = -(1ll << 60);
  for(int i = 0;i+k <= n;i++){
    ll sum = 0;
    sum = ps[i]-ps[0]+ps[n]-ps[i+k];
    sum += max(s[i+k]-s[i],0ll);
    res = max(res,sum);
  }
  cout << res << endl;




  return 0;
}