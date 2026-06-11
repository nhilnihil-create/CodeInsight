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

  vector<int> a(2 * N - 1);
  for (int i = 0; i < (int)(2 * N - 1); ++i) a[i] = i + 1;

  if (x < N) {
    rotate(a.begin(), a.begin() + x, a.begin() + N);
  } else if (x > N) {
    rotate(a.begin() + N - 1, a.begin() + x - 1, a.end());
  }

  cout << "Yes" << endl;
  for (int i = 0; i < (int)(2 * N - 1); ++i) cout << a[i] << endl;
  return 0;
}
