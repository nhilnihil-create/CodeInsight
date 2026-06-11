#include <bits/stdc++.h>
#define rep(i, to) for (int i = 0; i < (to); ++i)
#define repf(i, from, to) for (int i = (from); i < (to); ++i)
#define unless(cond) if (!(cond))
using namespace std;
using ll = long long;
template <typename T>
using V = vector<T>;
template <typename T, typename U>
using P = pair<T, U>;

int main() {
  int n;
  V<int> a;
  cin >> n;
  a.resize(n + 1);
  repf(i, 1, n + 1) {
    cin >> a[i];
  }

  int label = 1;
  int push_count = 0;
  V<bool> visited(n + 1, false);
  bool can = false;
  while(true) {
    if(visited[label]) {
      break;
    }
    if(label == 2) {
      can = true;
      break;
    }

    push_count++;
    visited[label] = true;
    label = a[label];
  }

  if(can) {
    cout << push_count << endl;
  } else {
    cout << - 1 << endl;
  }
}
