#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < m; i++){
    int x, y;
    cin >> x >> y;
    x--; y--;
    a[x]++; a[y]++;
  }
  for (int i = 0; i < n; i++){
    cout << a[i] << endl;
  }
}