#include <bits/stdc++.h>
using namespace std;
#define rep(i, ns, ne) for (int i = ns; i < ne; ++i)

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, L;
  cin >> N >> L;
  string v[102];
  rep(i, 0, N) { cin >> v[i]; }
  sort(v, v + N);
  rep(i, 0, N) { cout << v[i]; }
  cout << endl;
  getchar();
}