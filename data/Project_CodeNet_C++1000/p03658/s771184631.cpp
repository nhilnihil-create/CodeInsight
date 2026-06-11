#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int, int>;
typedef vector<int> vi;

int main() {
  int N, K;
  int ans = 0;
  int l[60];
  cin >> N >> K;
  rep(i, N) cin >> l[i];

  sort(l, l+N, greater<int>());
  rep(i, K) ans += l[i];

  cout << ans << endl;

  return 0;
}