#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;

int main() {
  int n; cin >> n;

  vector<ll> a(3*n+10);

  for (int i = 0; i < 3*n; i++) {
    cin >> a[i];
  }

  // 昇順に処理する
  priority_queue< ll, vector<ll>, greater<ll> > que;
  ll tmp = 0;

  for (int i = 0; i < n; i++) {
    que.push(a[i]);
    tmp += a[i];
  }

  vector<ll> memo_a(3*n+5);
  memo_a[n-1] = tmp;

  for (int k = n; k <= 2*n; k++) {
    que.push(a[k]);
    tmp += a[k];
    tmp -= que.top();
    memo_a[k] = tmp;
    que.pop();
  }


  // 降順に処理する
  priority_queue<ll> que2;
  tmp = 0;

  for (int i = 3*n-1; i >= 2*n; i--) {
    que2.push(a[i]);
    tmp += a[i];
  }

  vector<ll> memo_b(3*n+5);
  memo_b[2*n] = tmp;

  for (int k = 2*n-1; k >= n-1; k--) {
    que2.push(a[k]);
    tmp += a[k];
    tmp -= que2.top();
    memo_b[k] = tmp;
    que2.pop();
  }

  ll ans = -1e18;
  
  for (int k = n-1; k < 2*n; k++) {
    ans = max(ans, memo_a[k] - memo_b[k+1]);
  }

  cout << ans << endl;

  return 0;

}