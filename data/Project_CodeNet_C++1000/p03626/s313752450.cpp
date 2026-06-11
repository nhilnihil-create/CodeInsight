#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int mod = 1000000007;
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }
};

int main() {
  mint ans=1;
  int n;
  cin >> n;
  int now=0;
  string s;
  cin >> s;
  rep(i,n){
    if(s[i]==s[i+1]){
      if(now==0) ans*=6;
      if(now==1) ans*=2;
      if(now==2) ans*=3;
      now=2;
      i++;
    }
    else{
      if(now==0) ans*=3;
      if(now==1) ans*=2;
      if(now==2) ans*=1;
      now=1;
    }
  }
  cout << ans.x << endl;
      
  
}
