#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;

int main(){
  ll n, a, b;
  cin >> n >> a >> b;
  vector<ll> x(n);
  rep(i, n) cin >> x[i];
  ll ans = 0;
  for(int i = 1; i < n ;++i){
    ll walk = (x[i] - x[i - 1]) * a;
    ans += min(walk, b);
  }

  cout << ans << endl;
}