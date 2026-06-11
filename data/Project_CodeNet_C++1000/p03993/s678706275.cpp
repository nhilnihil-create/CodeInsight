#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
using pii = pair<int, int>;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (i == a[a[i - 1] - 1]) {
      count++;
    }
  }

  /* for (int i = 1; i < n + 1; i++) {
    for (int j = i + 1; j < n + 1; j++) {
      if (a[i] == j && a[j] == i) count++;
    }
  } */

  cout << count / 2 << endl;
}

//問題の概要
// ある数列が与えられます、i<jのときa[i] == j && a[j] ==
// iとなるのはいくつありますか?
