#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using P = pair<int,int>;
using ll = long long;
static const int INF = 1000000000;
static const ll MOD = 1000000007;

ll gcd(ll a, ll b){return b!=0 ? gcd(b, a%b) : a;}
ll lcm(ll a, ll b){return a / gcd(a, b) * b;}

int main(){
	ll n, x;
  cin >> n >> x;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll ans = 0;
  for(int i = 0; i < n-1; ++i){
    if(a[i] + a[i+1] > x){
      ll tmp = a[i] + a[i+1] - x;
      ans += tmp;
      if(a[i+1] >= tmp){
        a[i+1] -= tmp;
      }
      else{
        a[i] -= tmp - a[i+1];
        a[i+1] = 0;
      }
    }
  }

  cout << ans << endl;
	return 0;
}

