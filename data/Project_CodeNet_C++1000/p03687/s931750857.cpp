#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
#define REP(i,n) for(int i=1;i<=(n);++i)
#define pa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
#define pb push_back

using ll = long long;
using namespace std;
using pint = pair<int,int>;
using pll = pair<ll,ll>;
const int INFint = 2e9+1;
const ll INFll = 2e18+1;
ll MOD=1e9+7;

ll gcd(ll a, ll b) { return __gcd(a,b); } //最大公約数
ll lcm(ll a, ll b) { return a/gcd(a,b)*b; } //最大公倍数

// aのn乗をMODで割りながら計算する
ll modpow(ll a, ll n) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % MOD;
    a = a * a % MOD;
    n >>= 1; // right shift
  }
  return res;
}

// MODを法としたaの逆元を計算する
ll modinv(ll a) {
  return modpow(a, MOD - 2);
}
bool check(string s,char c){
  bool flag = true;
  for (int i(0);i<int(s.size());i++){
    if (s[i] != c){
      flag = false;
    }
  }
  return flag;
}

int main(){
  string s;
  cin>>s;
  int N = int(s.size());
  int cnt[30] = {0};
  rep(i,N){
    cnt[s[i]-'a']++;
  }
  int ans(1e9);
  for(int i(0);i<30;i++){
    if (cnt[i] != 0){
      char c = (char)('a' + i);
      string t = s;
      int cnti(0);
      // cout << c << endl;
      while(!check(t,c)){
        string ti(int(t.size()-1),'.');
        for (int j(0);j<int(t.size())-1;j++){
          if (t[j] == c || t[j+1] == c){
            ti[j] = c;
          }else{
            ti[j] = t[j];
          }
        }
        cnti++;
        t = ti;
      }
      ans = min(ans,cnti);
    }
  }
  cout << ans << endl;
  return 0;
}

