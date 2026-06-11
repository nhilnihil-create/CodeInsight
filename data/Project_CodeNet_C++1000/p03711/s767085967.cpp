#include <bits/stdc++.h>

#define REP(i, x) REPI(i, 0, x)
#define REPI(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int x, y;
  cin >> x >> y;
  vector<int> a = {1, 3, 5, 7, 8, 10, 12};
  vector<int> b = {4, 6, 9, 11};

  if (find(a.begin(), a.end(), x) != a.end()) {
    if (find(a.begin(), a.end(), y) != a.end()) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  if (find(b.begin(), b.end(), x) != b.end()) {
    if (find(b.begin(), b.end(), y) != b.end()) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;

  return 0;
}
