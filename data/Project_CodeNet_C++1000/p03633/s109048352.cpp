#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main(){
  int n;
  cin >> n;

  vector<ll> t(n);
  rep(i,n) cin >> t.at(i);

  ll ans=t.at(0);
  rep(i,n) ans=lcm(ans, t.at(i));

  cout << ans;
}