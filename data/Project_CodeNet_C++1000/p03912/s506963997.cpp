#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define INF (1000000000000)
#define NIL (-1)
using namespace std;

int main(){
  ll n,m;
  cin >> n >> m;

  vector<ll> x(100001,0);
  vector<ll> mod(m);
  vector<ll> mod2(m);
  for(ll i = 0; i < n; i++){
    ll temp;
    cin >> temp;
    x[temp]++;
  }
  for(ll i = 0; i < 100001; i++){
    mod[i%m]+= x[i];
    mod2[i%m] += x[i]/2;
  }

  ll ans = 0;
  ll ans2 = 0;
  ll ans3 = 0;
  ans += mod[0] / 2;

  if(m %2 != 0){
    for(ll i = 1; i <= m/2; i++){
      ans += min(mod[i], mod[m-i]);
      ans2 += min(mod2[i], (mod[i] - min(mod[i],mod[m-i]))/2);
      ans2 += min(mod2[m-i], (mod[m-i] - min(mod[i], mod[m-i]))/2);
    }
  }else{
    for(ll i = 1; i < m/2; i++){
      ans += min(mod[i], mod[m-i]);
      ans2 += min(mod2[i], (mod[i] - min(mod[i],mod[m-i]))/2);
      ans2 += min(mod2[m-i], (mod[m-i] - min(mod[i], mod[m-i]))/2);
    }
    ans += mod[m/2] / 2;
  }

  cout << ans + ans2 << endl;

}
