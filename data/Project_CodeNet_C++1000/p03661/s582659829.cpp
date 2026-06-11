#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;

ll l[1000000];
void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> l[i];
  ll tot = 0;
  for(int i = 0; i < n; i++) tot += l[i];
  ll ret = 1e18;
  ll curr = 0;
  for(int i = 0; i < n-1; i++) {
    curr += l[i];
    ret = min(ret, abs(2*curr - tot));
  }
  cout << ret << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}
