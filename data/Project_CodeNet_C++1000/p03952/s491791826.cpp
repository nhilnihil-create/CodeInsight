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
  vector<int> a(2 * N - 1, 0);

  int i = N - 1, k = x - 1;
  for (int j = 0; j < (int)(2 * N - 1); ++j) {
    a[i] = k + 1;
    k = (k + 1) % (2 * N - 1);
    i = (i + 1) % (2 * N - 1);
  }

  cout << "Yes" << endl;
  for (int i = 0; i < (int)(2 * N - 1); ++i) cout << a[i] << endl;
  return 0;
}
