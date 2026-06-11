#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#define rep2(i,x,y) for (int i = x; i < (y); ++i)
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long int ll;
template<class T, class U> bool has_key(T mp, U key) { return mp.find(key) != mp.end(); }
const ll mod = 1000000007;
using namespace std;

map<ll, ll> factorint(ll n){
  map<ll, ll> res;
  do{
    top:
    for(ll i = 2; i < sqrt(n)+1000; i++){
      if(n % i == 0){
        if(res.find(i) == res.end()) res[i] = 0;
        res[i]++;
        n /= i;
        goto top;
      }
    }
    if( n != 1) res[n] = 1;
    break;
  } while(true);
  return res;
}

int main()
{
  ios::sync_with_stdio(false);  cin.tie(0); cout.tie(0);
  ll n;
  cin >> n;
  map<ll,ll> allf;
  ll ans = 1;
  rep2(i, 1, n+1){
    auto f = factorint(i);
    for(auto el: f){
      if(! has_key(allf, el.first)){
        allf[el.first] = el.second;
      }else{
        allf[el.first] += el.second;
      }
    }
  }
  for(auto el: allf){
    ans %= mod;
    //cout << el.first << " " << el.second << endl;
    ans = (ans * (el.second + 1)) % mod;
  }
  cout << ans << endl;
  return 0;
}