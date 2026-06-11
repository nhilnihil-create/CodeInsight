#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep2(i, a, n) for(ll i = a; i < (ll)(n); i++)
#define memi cout << endl
#define kono(n) cout << fixed << setprecision(n)
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define hina cout << ' '
#define in(n) cin >> n
#define in2(n, m) cin >> n >> m
#define in3(n, m, l) cin >> n >> m >> l
#define out(n) cout << n
const ll mei = (ll)1e9 + 7;

int main(){
  ll n, a, i;
  in(n);
  string s, t;
  in2(s, t);
  ll dp[n];
  if(s[0] == t[0]){
    a = 0;
    i = 1;
    dp[0] = 3;
  }
  else{
    a = 1;
    i = 2;
    dp[1] = 6;
  }
  while(i < n){
    if(a == 0){
      if(s[i] == t[i]){
        dp[i] = 2 * dp[i - 1] % mei;
        i++;
      }
      else{
        dp[i + 1] = 2 * dp[i - 1] % mei;
        a = 1;
        i += 2;
      }
    }
    else{
      if(s[i] == t[i]){
        dp[i] = dp[i - 1] % mei;
        a = 0;
        i++;
      }
      else{
        dp[i + 1] = 3 * dp[i - 1] % mei;
        i += 2;
      }
    }
  }
  out(dp[n - 1]);
  memi;
}
