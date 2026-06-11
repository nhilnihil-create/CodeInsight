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
	int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  sort(a.begin(), a.end());

  vector<ll> cumsum(n+1, 0);
  for(int i = 0; i < n; ++i){
    cumsum[i+1] = cumsum[i] + a[i];
  }
  sort(cumsum.rbegin(), cumsum.rend());

  ll ans = 1;
  for(int i = 0; i < n; ++i){
    if(2 * cumsum[i+1] >= cumsum[i] - cumsum[i+1]){
      ans++;
    }
    else{
      break;
    }
  }

  cout << ans << endl;
	return 0;
}

