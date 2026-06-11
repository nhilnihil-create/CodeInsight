#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  priority_queue <int> pq;
  for (int i = 0; i < 2*n; i++) {
    int a;
    cin >> a;
    pq.push(a);
  }
  int ans = 0;
  for (int i = 0; i < 2*n; i++) {
    if (i%2 == 1) {
      ans += pq.top();
    }
    pq.pop();
  }
  cout << ans << endl;
}