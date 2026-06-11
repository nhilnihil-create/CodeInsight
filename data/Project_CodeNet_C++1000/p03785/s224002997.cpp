#include <iostream>
#include <queue>

using namespace std;

int main() {
  int N, C, K, T, t, c{}, ans{};
  cin >> N >> C >> K;
  priority_queue<int, vector<int>, greater<int>> q;
  while(cin >> T) q.push(T);
  t = -K;
  while(!q.empty()) {
    int x = q.top();
    q.pop();
    if (x > t+K || c == C) {
      ++ans;
      t = x;
      c = 0;
    }
    ++c;
  }
  cout << ans << endl;
}
