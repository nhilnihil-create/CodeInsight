#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
const int INF = 1e9;
const int MOD = 1000000007;
#define rep(i,n) for(int i=0;i<n;i++)
 
int main() {
  ll n,a,b;
  cin >> n >> a >> b;
  vector<ll> x(n);
  rep(i,n) cin >> x.at(i);
  ll ans = 0;
  rep(i,n-1){
    ans += min(a*(x.at(i+1)-x.at(i)),b);
  }
  cout << ans << endl;
  
  return 0;
}


