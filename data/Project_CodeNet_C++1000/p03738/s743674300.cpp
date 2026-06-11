#include <bits/stdc++.h>
#define rep(i, f, n) for (ll i = (f); i < (ll)(n); i++)
#define repe(i, f, n) for (ll i = (f); i <= (ll)(n); i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
  string A, B;
  cin >> A >> B;

  if (A.size() > B.size()) {
    cout << "GREATER" << endl;
  } else if (A.size() < B.size()) {
    cout << "LESS" << endl;
  } else {
    int a = A.compare(B);
    if (a > 0) {
      cout << "GREATER" << endl;
    } else if (a < 0) {
      cout << "LESS" << endl;
    } else {
      cout << "EQUAL" << endl;
    }
  }

  return 0;
}
