#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
#define int long long

typedef pair<int, int> P;

signed main() {
  int h, w;
  cin >> h >> w;
  int n;
  cin >> n;
  map<P, int> m;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    for (int j = a - 2; j <= a; j++) {
      for (int k = b - 2; k <= b; k++) {
        if (1 <= j && j + 2 <= h && 1 <= k && k + 2 <= w) {
          m[P(j, k)]++;
        }
      }
    }
  }
  int count[10];
  fill(count, count + 10, 0);
  for (auto i = m.begin(); i != m.end(); i++) {
    count[i->second]++;
  }
  /*
  for (auto i = m.begin(); i != m.end(); i++) {
    cout << i->first.first << " " << i->first.second << " " << i->second << endl;
  }
  */
  int sum = 0;
  for (int i = 1; i < 10; i++) {
    sum += count[i];
  }
  cout << (h - 2) * (w - 2) - sum << endl;
  for (int i = 1; i < 10; i++) {
    cout << count[i] << endl;
  }
  return 0;
}
