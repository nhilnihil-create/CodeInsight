#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin>>n>>k;
  int a[n];
  for (int i=0; i<n; i++) cin>>a[i];
  vector<int> b;
  for (int i=0; i<n; i++) {
    if (a[i] < k) {
      b.push_back(a[i]);
    }
  }
  int size = b.size();
  bool dp_left[size+1][k], dp_right[size+1][k];
  for (int i=0; i<=size; i++) {
    for (int j=0; j<k; j++) {
      dp_left[i][j] = false;
      dp_right[i][j] = false;
    }
  }
  dp_left[0][0] = true;
  for (int i=1; i<=size; i++) {
    for (int j=0; j<k; j++) {
      dp_left[i][j] = dp_left[i][j] || dp_left[i-1][j];
      if (j + b[i-1] < k && dp_left[i-1][j]) {
        dp_left[i][j+b[i-1]] = true;
      }
    }
  }
  dp_right[size][0] = true;
  for (int i=size-1; i>=0; i--) {
    for (int j=0; j<k; j++) {
      dp_right[i][j] = dp_right[i][j] || dp_right[i+1][j];
      if (j + b[i] < k && dp_right[i+1][j]) {
        dp_right[i][j+b[i]] = true;
      }
    }
  }
  int ans = 0;
  for (int i=0; i<size; i++) {
    vector<int> left;
    for (int j=0; j<k; j++) {
      if (dp_left[i][j]) {
        left.push_back(j);
      }
    }
    vector<int> right;
    for (int j=0; j<k; j++) {
      if (dp_right[i+1][j]) {
        right.push_back(j);
      }
    }
    bool found = false;
    for (int x: left) {
      auto it = lower_bound(right.begin(), right.end(), k - x - b[i]);
      if (it == right.end()) {
        continue;
      }
      int v = *it;
      if (x + v < k && x + v + b[i] >= k) {
        found = true;
        break;
      }
    }
    if (!found) {
      ++ans;
    }
  }
  cout<<ans<<endl;
}