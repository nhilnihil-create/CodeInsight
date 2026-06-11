#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const ll INF = 1LL<<60;

int main()
{
  ll N, K;cin>>N>>K;
  ll ans = K;
  for (int i = 1; i < N; i ++) ans *= (K - 1);
  cout << ans << endl;
  return 0;
}