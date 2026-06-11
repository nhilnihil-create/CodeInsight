#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int DEBUG = 0;

template<typename T>
vector<vector<T>> Make2DVector(int d1, int d2, T default_value) {
  return vector<vector<T>>(d1, vector<T>(d2, default_value));
}

// Vector
template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
  int len = v.size();
  s << "[";
	for (int i = 0; i < len; i++) {
    if (i > 0) s << ", ";
		s << v[i];
  }
  s << "]";
  return s;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;
  vector<int> xs;
  for (char c : s) xs.push_back(c - 'a');

  int n = xs.size();
  auto dp = Make2DVector(n, 26, n);
  dp[n - 1][xs[n - 1]] = n - 1;
  for (int i = n - 2; i >= 0; i--) {
    for (int j = 0; j < 26; j++) {
      dp[i][j] = dp[i + 1][j];
    }
    dp[i][xs[i]] = i;
  }

  auto get_ans_fn = [&]() -> vector<int> {
    vector<int> prevs(n, -2);
    deque<int> q;
    q.push_back(-1);
    vector<int> visited(n);

    auto dump_path_fn = [&](int k) -> vector<int> {
      vector<int> path;
      while (k >= 0) {
        // cout << "k: " << k << endl;
        path.push_back(xs[k]);
        k = prevs[k];
      }
      reverse(path.begin(), path.end());
      return path;
    };

    while (!q.empty()) {
      int i = q.front();
      q.pop_front();
      if (i + 1 >= n) {
        auto path = dump_path_fn(i);
        path.push_back(0);
        return path;
      }
      for (int j = 0; j < 26; j++) {
        int k = dp[i + 1][j];
        if (k >= n) {
          auto path = dump_path_fn(i);
          path.push_back(j);
          return path;
        }

        if (visited[k]) continue;
        prevs[k] = i;
        q.push_back(k);
        visited[k] = 1;
      }
    }
    cerr << "Unexpected!" << endl;
    exit(1);
  };

  auto ans = get_ans_fn();
  for (int x : ans) {
    cout << static_cast<char>('a' + x);
  }
  cout << endl;
}
