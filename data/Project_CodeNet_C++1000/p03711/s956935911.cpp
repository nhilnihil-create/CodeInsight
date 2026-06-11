#include<bits/stdc++.h>
using namespace std;
int main() {
  int x, y; cin >> x >> y;
  vector<int> s = {0, 1, 0, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1};
  cout << ((s[x] == s[y]) ? "Yes" : "No") << endl;
}