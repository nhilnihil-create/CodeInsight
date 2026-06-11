#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int calc(pair<int, int> stu, pair<int, int> check) {
  return abs(stu.first - check.first) + abs(stu.second - check.second);
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> stu(n), check(m);
  for (int i = 0; i < n; i++) {
    cin >> stu[i].first >> stu[i].second;
  }
  for (int i = 0; i < m; i++) {
    cin >> check[i].first >> check[i].second;
  }

  for (int i = 0; i < n; i++) {
    int min = 999999999;
    for (int j = 0; j < m; j++) {
      min = std::min(min, calc(stu[i], check[j]));
    }
    for (int j = 0; j < m; j++) {
      int temp = calc(stu[i], check[j]);
      if (min == temp) {
        cout << j + 1 << endl;
        break;
      }
    }
  }
}