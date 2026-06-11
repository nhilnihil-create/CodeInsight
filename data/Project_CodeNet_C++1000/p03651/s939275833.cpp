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
	ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  vector<ll> kk;
  rep(i, n){
    if(k == a[i]){
      cout << "POSSIBLE" << endl;
      return 0;
    }
    else if(k < a[i]){
      kk.push_back(a[i] - k);
    }
  }

  if(!kk.empty()){
    ll tmp = a[0];
    for(int i = 1; i < n; ++i){
      tmp = gcd(tmp, a[i]);
    }
    for(int i = 0; i < kk.size(); ++i){
      if(kk[i] % tmp == 0){
        cout << "POSSIBLE" << endl;
        return 0;
      }
    }
  }
  cout << "IMPOSSIBLE" << endl;
	return 0;
}

