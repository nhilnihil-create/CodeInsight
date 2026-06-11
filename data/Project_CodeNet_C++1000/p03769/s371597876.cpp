#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

vector<int> Solve() {
  int64 n;
  cin >> n;
  if (n == 1) {
    return vector<int>({1, 1});
  }
  vector<char> ops;
  while (n > 1) {
    if (n % 2 == 1) {
      ops.push_back('*');
      n--;
      n /= 2;
    } else {
      ops.push_back('+');
      n--;
    }
  }
  reverse(ops.begin(), ops.end());

  int k = ops.size() + 1;
  deque<int> q;
  q.push_back(1);
  for (int i = 2; i <= k; i++) {
    char op = ops[i - 2];
    if (op == '+') {
      q.push_front(i);
    } else {
      q.push_back(i);
    }
  }
  
  vector<int> v;
  for (int i = 1; i <= k; i++) {
    v.push_back(i);
  }
  v.insert(v.end(), q.begin(), q.end());
  return v;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  auto v = Solve();
  cout << v.size() << endl;
  for (int x : v) {
    cout << x << " ";
  }
  cout << endl;
}