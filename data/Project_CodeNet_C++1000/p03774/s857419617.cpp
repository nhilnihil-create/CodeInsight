#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int dist(pair<int, int> &a, pair<int, int> &b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
  int N, M;
  cin >> N >> M;

  vector<pair<int, int>> s(N), c(M);
  for (int i = 0; i != N; ++i) {
    cin >> s[i].first >> s[i].second;
  }
  for (int i = 0; i != M; ++i) {
    cin >> c[i].first >> c[i].second;
  }

  for (int i = 0; i != N; ++i) {
    cout << min_element(begin(c), end(c),
                [&](pair<int, int> &a, pair<int, int> &b) {
                  return dist(a, s[i]) < dist(b, s[i]);
                }
                ) - begin(c) + 1
         << endl;
  }

  return 0;
}
