#include <bits/stdc++.h>
using namespace std;
int main() {
  set<int> c;
  for (int i=0; i<3; i++) {
    int t;
    cin >> t;
    c.insert(t);
  }
  cout << c.size() << endl;
}