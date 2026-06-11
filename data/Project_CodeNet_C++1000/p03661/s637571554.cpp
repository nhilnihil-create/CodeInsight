#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define All(V) V.begin(), V.end()
typedef long long int ll;
typedef pair<int, int> P;
const ll MOD = 1e9+7, INF = 1e9;

int main()
{
  int n; cin >> n;
  vector<ll> v(n);
  rep(i, n) cin >> v[i];
  vector<ll> sum_front(n+1, 0), sum_back(n+1, 0);
  for(int i = 0; i < n; i++){
    sum_front[i+1] = sum_front[i]+v[i];
    sum_back[i+1] = sum_back[i] + v[n-i-1];
  }
  ll ans = 1e10;
  for(int i = 1; i <= n-1; i++){
    ans = min(ans, abs(sum_front[i]-sum_back[n-i]));
  }
  cout << ans << endl;
  system("pause");
}