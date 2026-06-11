#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
  int n;
  cin >> n;
  deque<int> a;
  rep(i,n) {
    int b; cin >> b;
    if (i % 2 == 0) a.push_front(b);
    else a.push_back(b);
  }

  if (n % 2 == 1) {
    rep(i,n) cout << a[i] << ' ';
  } else {
    rep(i,n) cout << a[n-i-1] << ' ';
  }
  cout << endl;
  return 0;
}