#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, a, b;
  cin >> n >> m;
  vector<int> data(n);
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    data.at(a - 1) = data.at(a - 1) + 1; 
    data.at(b - 1) = data.at(b - 1) + 1;
  }
  for (int i = 0; i < n; i++) {
    cout << data.at(i) << endl;
  }
}  