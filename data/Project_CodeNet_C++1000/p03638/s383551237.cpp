#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int h, w, n;
  cin >> h >> w >> n;
  vector<int> va;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    for (int j = 0; j < a; ++j) {
      va.push_back(i + 1);
    }
  }

  for (int i = 0; i < h; ++i) {
    vector<int> ans;
    for (int j = i * w; j < i * w + w; ++j) {
      ans.push_back(va[j]);
    }

    for (int j = 0; j < ans.size(); ++j) {
      if (j != 0) {
        cout << ' ';
      }

      if (i % 2 == 0) {
        cout << ans[j];
      } else {
        cout << ans[ans.size() - j - 1];
      }
    }

    cout << '\n';
  }

  return 0;
}