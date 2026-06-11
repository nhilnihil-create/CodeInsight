#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i,a,b) for (ll i=a;i<=ll(b);i++)
using namespace std;

ll ctoi(const char c){if('0'<=c&&c<='9') return (c-'0');return -1;}
#define ALL(x) begin(x),end(x)
  
int main(){
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  ll ans = 0;
  
  rep(i,n){
    if(a[a[i]-1] == i+1) ans++;
    a[i] = -1; //相思相愛うさぎ併せて１カウントする
  }
  
  cout << ans << endl;
  
}