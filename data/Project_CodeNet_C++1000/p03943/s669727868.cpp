#include <bits/stdc++.h>
#define rep(i, ns, ne) for (int i = ns; i < ne; ++i)
using namespace std;
int main() {
  vector<int> v(3);
  rep(i, 0, 3) { cin >> v[i]; }
  sort(v.begin(), v.end());
  cout << ((v[0] + v[1] == v[2]) ? "Yes" : "No") << endl;
  getchar();
}