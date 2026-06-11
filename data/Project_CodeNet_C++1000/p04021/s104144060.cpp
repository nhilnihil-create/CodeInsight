#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
int main() {
  int N;
  cin >> N;
  priority_queue<P, vector<P>, greater<P>> que;
  for (int i = 0; i < N; i++) {
    int a; cin >> a;
    que.push(P(a, i));
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    P p = que.top(); que.pop();
    if (i % 2 == 0 && p.second % 2 == 1) {ans++;}
  }
  cout << ans << endl;
}