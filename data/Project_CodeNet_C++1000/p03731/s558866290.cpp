#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define All(V) v.begin(), v.end()
typedef long long int ll;
typedef pair<int, int> P;
const ll MOD = 1e9+7, INF = 1e9;

int main()
{
  int n; cin >> n;
  ll t; cin >> t;
  ll ans = t;
  vector<ll> v(n);
  rep(i, n) cin >> v[i];
  for(int i = 0; i < n-1; i++){
    if(v[i+1]-v[i] <= t) ans += v[i+1]-v[i];
    else{
      ans += t;
    }
  }
  cout << ans << endl;
  system("pause");
}