#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; ++i) {
    cin >> a[i]; --a[i];
  }
  set<int> se;
  se.insert(0);
  int cur = 0;
  while (true) {
    cur = a[cur];
    if (cur == 1) break;
    if (se.count(cur)) {
      cout << -1 << endl;
      return 0;
    }
    se.insert(cur);
  }
  cout << se.size() << endl;
}
  
  
  