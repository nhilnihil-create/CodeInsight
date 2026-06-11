#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int n;

vector<int> rec(int i, vector<int> b) {
  if (b.size() == n) return b;
  b.insert(b.end(), i + 1);
  b.insert(b.begin(), i + 2);
  return rec(i + 2, b);
}

int main() {
  int n, a;
  cin >> n;
  deque<int> d;
  rep(i, n) {
    cin >> a;
    if (i % 2 == n % 2) {
      d.push_back(a);
    } else {
      d.push_front(a);
    }
  }

  rep(i, n) {
    cout << d[i];
    if (i != n - 1) cout << ' ';
  }
  cout << endl;
  return 0;
}
