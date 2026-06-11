#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m;
  cin >> n >> m;
  vector<int> vec(n,0);
  int k,l;
  for (int i = 0; i < m; i++) {
    cin >> k >> l;
    vec.at(k-1) += 1;
    vec.at(l-1) += 1;
  }
  for (int i = 0; i < n; i++) {
    cout << vec.at(i) << endl;
  }
}