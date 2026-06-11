#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int n; cin >> n;
  vector<int> arr(n);

  for (int i = 0; i < n; ++i) cin >> arr[i];

  bool visited[n];
  memset(visited, false, sizeof(visited));

  int buttons_pressed = 0;
  queue<int> q({1});
  while (!q.empty() && !visited[q.front() - 1]) {
    int current_button = q.front(); q.pop();
    int next_button = arr[current_button - 1];
    buttons_pressed++;

    if (next_button == 2) {
      cout << buttons_pressed << "\n";
      return 0;
    }

    visited[current_button - 1] = true;
    q.push(next_button);
  }
  cout << -1 << "\n";
}
