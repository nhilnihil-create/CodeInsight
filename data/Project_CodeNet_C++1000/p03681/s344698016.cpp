#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#include<algorithm>//next_permutation
#define rep(i,n) for (int i = 0;i < (n);i++)
#define all(v) v.begin(),v.end()
#define dec(n) cout << fixed << setprecision(n);
#define large "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define small "abcdefghijklmnopqrstuvwxyz"
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vl>;

ll gcd(ll a,ll b){
  if(b == 0) return a;
  return gcd(b , a % b);
}

const ll MOD = 1000000007;
const ll MAX = 2000001;

ll mod(ll a){
  return a % MOD;
}

ll lcm(ll a,ll b){
  return (a*b)/gcd(a,b);
}


int main(){
  ll a,b; cin >> a >> b;
  
  if(abs(a-b) >= 2){
    cout << 0 << endl;
    return 0;
  }
  
  ll ans = 1;
 
    rep(i,a){
      ans *= i+1;
      ans = mod(ans);
    }
    rep(i,b){
      ans *= i+1;
      ans = mod(ans);
    }
  
  if(abs(a-b) == 1){
    cout << ans << endl;
  }
  else cout << mod(ans*2) << endl;
  
  
}