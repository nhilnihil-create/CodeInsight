#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> r(n, 0);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    r[a-1] += 1;
    r[b-1] += 1;
  }

  for (int i = 0; i < n; i++) {
    cout << r[i] << endl;
  }
  
}
