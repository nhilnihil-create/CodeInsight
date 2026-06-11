#include <bits/stdc++.h>
       
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
  int N, x;
  cin >> N >> x;

  if (x == 1 || x == 2 * N - 1) {
    cout << "No" << endl;
    return 0;
  }

  if (N == 2) {
    cout << "Yes" << endl;
    cout << "1 2 3" << endl;
    return 0;
  }

  vector<int> a(2 * N - 1, 0);
  vector<bool> used(2 * N, false);

  used[x] = true;
  used[x - 1] = true;
  used[x + 1] = true;
  if (x == 2) {
    a[N - 2] = x + 1;
    a[N - 1] = x;
    a[N] = x - 1;
    a[N + 1] = x + 2;
    used[x + 2] = true;
  } else {
    a[N - 2] = x - 1;
    a[N - 1] = x;
    a[N] = x + 1;
    a[N + 1] = x - 2;
    used[x - 2] = true;
  }

  int j = 1;
  for (int i = 0; i < (int)(2 * N - 1); ++i) {
    if (a[i] != 0) continue;
    while (used[j]) ++j;
    a[i] = j++;
  }

  cout << "Yes" << endl;
  for (int i = 0; i < (int)(2 * N - 1); ++i) cout << a[i] << endl;
  return 0;
}
