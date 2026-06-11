#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

ll calcNumOfCombination(ll n, ll r){
  ll num = 1;
  for(ll i = 1; i <= r; i++){
    num = num * (n - i + 1) / i;
  }
  return num;
}

int main(){
  int n, a, b;
  cin >> n >> a >> b;
  vector<ll> v(n);
  map<ll, int> mp;
  rep(snip_i, n){
    cin >> v.at(snip_i);
    mp[v.at(snip_i)]++;
  }
  sort(v.begin(), v.end());
  ll sum = 0, me = -1;
  int mec = 0;
  for(int i = n-a; i < n; i++){
    sum += v.at(i);
    if(me == -1) me = v.at(i);
    if(v.at(i) == me) mec++;
  }
  double ave = (double)sum/a;
  printf("%.10f\n", ave);
  ll ans2;
  if(mec == a){
    ans2 = 0;
    rep2(i, mec, b+1){
      ans2 += calcNumOfCombination(mp[me], i);
      // cerr << ans2 << endl;
    }
  }else{
    ans2 = calcNumOfCombination(mp[me], mec);
  }
  cout << ans2 << endl;

  return 0;
}