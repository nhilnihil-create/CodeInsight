#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vii = vector<vi>;
using Pll = pair<ll, ll>;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(v) v.begin(), v.end()
#define sz(x) ((int) x.size())
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define F first
#define S second
const int MOD = 1e9+7;
const int INF = 2e9;
template<class T> void print(const T& t){ cout << t << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}

int main(){
  ll n;
  cin >> n;
  ll ans = 0;
  vi s(n);
  rep(i, n){
    cin >> s[i];
    ans += s[i];
  }
  if(ans%10!=0){
    print(ans);
  }
  else{
    sort(all(s));
    bool z = true;
    rep(i, n){
      if((ans-s[i])%10!=0){
        print(ans - s[i]);
        z = false;
        break;
      }
    }
    if(z){
      print(0);
    }
  }
}