#include <bits/stdc++.h>

using namespace std;

int main(void) {
  int n;
  cin >> n;

  int p = 1;
  vector<int> ans;
  while (true) {
    if (n < p) {
      break;
    }
    n -= p;
    ans.push_back(p++);
  }

  for (int i = 0; i < n; i++) {
    ans[ans.size() - i - 1]++;
  }

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << endl;
  }

  return 0;
}