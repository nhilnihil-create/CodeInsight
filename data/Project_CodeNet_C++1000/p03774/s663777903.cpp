#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 
  
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> students(n);
  for (int i = 0; i < n; ++i) {
    int x, y; cin >> x >> y;
    students[i] = {x, y};
  }

  vector<pair<int, int>> checkpoints(m);
  for (int i = 0; i < m; ++i) {
    int x, y; cin >> x >> y;
    checkpoints[i] = {x, y};
  }

  for (int i = 0; i < n; ++i) {
    int result = 0;
    for (int j = 1; j < m; ++j) {
      int result_d = abs(checkpoints[result].first - students[i].first) +
        abs(checkpoints[result].second - students[i].second);
      int curr_d = abs(checkpoints[j].first - students[i].first) +
        abs(checkpoints[j].second - students[i].second);

      if (curr_d < result_d) result = j;
    }

    cout << result + 1 << "\n";
  }
}
