#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n; cin >> n;
  vector<pair<int, int>> b(n);

  for (int i = 0; i < n; i++) {
    int a; cin >> a;
    b[i] = make_pair(a, i);
  }
  sort(b.begin(), b.end());

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    // i: ソート後の順番, b[i].second: もとの数列の順番
    if ( (i & 1) != (b[i].second & 1) ) {
      cnt++;
    }
  }
  cout << cnt/2 << endl;
  return 0;
}