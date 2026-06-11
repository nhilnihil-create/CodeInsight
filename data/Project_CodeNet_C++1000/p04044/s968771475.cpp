#include <bits/stdc++.h>
using namespace std;
#define rep(i, ns, ne) for (int i = ns; i < ne; ++i)
#define rep2(i, ns, ne) for (int i = ns; i <= ne; ++i)

int main() {
  int N, L;
  cin >> N >> L;
  vector<string> v(N);
  rep(i, 0, N) { cin >> v[i]; }
  sort(v.begin(), v.end());
  for (auto s : v) {
    cout << s;
  }
  cout << endl;

  getchar();
}