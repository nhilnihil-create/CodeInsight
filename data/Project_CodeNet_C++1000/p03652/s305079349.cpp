#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

template<typename T>
vector<vector<T>> Make2DVector(int d1, int d2, T default_value) {
  return vector<vector<T>>(d1, vector<T>(d2, default_value));
}

template<class T> inline bool UpdateMin(T& a, T b) {
  if (a > b) { a = b; return 1; } return 0;
}

template<class T> inline bool UpdateMax(T& a, T b) {
  if (a < b) { a = b; return 1; } return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  auto orders = Make2DVector(n, m, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> orders[i][j];
      orders[i][j]--;
    }
  }

  vector<int> indexes(n, 0);
  vector<int> removed(m, 0);
  int ans = INT32_MAX;
  for (int k = 0; k < m; k++) {
    vector<int> counter(m);
    int max_value = -1;
    int max_arg = -1;
    for (int i = 0; i < n; i++) {
      int type = orders[i][indexes[i]];
      counter[type]++;
      if (UpdateMax(max_value, counter[type])) {
        max_arg = type;
      }
    }

    UpdateMin(ans, max_value);

    removed[max_arg] = 1;

    if (k == m - 1) break;
    
    for (int i = 0; i < n; i++) {
      while(removed[orders[i][indexes[i]]]) indexes[i]++;
    }
  }
  cout << ans << endl;
}
