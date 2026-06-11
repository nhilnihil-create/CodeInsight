#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LONG_LONG_MAX / 2;
const ll mod = 1000000000 + 7;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int N, M;
  cin >> N >> M;
  vector<pair<int, int>> students, pos;
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    students.push_back(make_pair(a, b));
  }

  for (int i = 0; i < M; i++) {
    int c, d;
    cin >> c >> d;
    pos.push_back(make_pair(c, d));
  }

  for (int i = 0; i < N; i++) {
    int dis_min = INT_MAX;
    int ans = INT_MAX;
    for (int j = 0; j < M; j++) {
      int dis = abs(students[i].first - pos[j].first) +
                abs(students[i].second - pos[j].second);
      if (dis < dis_min) {
        dis_min = dis;
        ans = j + 1;
      }
    }
    cout << ans << endl;
  }
}
