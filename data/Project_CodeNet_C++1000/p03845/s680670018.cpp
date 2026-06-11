#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n;
  vector<long long> t(n);
  for (int i= 0; i<n; i++) {
    cin >> t[i];
  }
  cin >> m;
  vector<int> p(m);
  vector<int> x(m);
  for (int k = 0; k<m; k++) {
    cin >> p[k] >> x[k];
  }
  long long count = 0;
  for (int i = 0; i<m; i++) {
    count = 0;
    for (int j = 0; j<n; j++) {
      count += t[j];
      if (j == n-1) {
        count += x.at(i) - t.at(p.at(i)-1);
        cout << count << endl;
      }
    }
  }
}