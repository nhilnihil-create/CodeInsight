#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  
  vector<bool> v(101, false);
  v[a] = 1;
  v[b] = 1;
  v[c] = 1;
  
  cout << accumulate(v.begin(), v.end(), 0) << endl;
}