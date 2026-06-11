#include <bits/stdc++.h>
using namespace std;
#define ll long long
template <typename T>
bool PN(T x){ if (x <= 1) return false; if (x == 2) return true; for (int i = 2; i < sqrt(x) + 1; i++) if (x % i == 0) return false; return true;}
const ll MOD = 1e9+7;
long long Comb(int n, int i){long long ans = 1; if(i == 0 || i == n) return 1; else {for(int j = 1; j <= i; ++j){
      ans *=(n+1-j);
      ans /= j;
      ans %= MOD;} }return ans;}


void solve()
{
  int n; cin >> n;
  bool visited[n+1];
  int go[n + 1];
  go[0] = 0;
  visited[0] = false;
  for(int i = 1; i <= n; ++i) {
    cin >> go[i];
    visited[i] = false;
  }
  int ans = 1;
  int now = go[1];
  visited[1] = true;
  visited[now] = true;
  while(now != 1){
    if(now == 2) {
      cout << ans << endl;
      return;
    }
    if(visited[go[now]]) break;
    visited[now] = true;
    now = go[now];
    ans++;
  }
  cout << -1 << endl;
}

int main()
{
  solve();
  return 0;
}
