#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define All(V) V.begin(), V.end()
typedef long long int ll;
typedef pair<int, int> P;
const ll MOD = 1e9+7, INF = 1e9;

int main()
{
  int n, cnt = 0; cin >> n;
  vector<ll> v(n);
  ll ans = 1;
  rep(i, n) cin >> v[i];
  sort(All(v), greater<ll>());
  for(int i = 0; i < n-1; i++){
    if(v[i] == v[i+1] && cnt != 2){
      i++;
      cnt++;
      ans *= v[i];
    }
  }
  if(cnt == 2) cout << ans << endl;
  else cout << "0" << endl;
  system("pause");
}
