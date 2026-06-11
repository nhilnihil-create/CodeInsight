#include <bits/stdc++.h>
using namespace std;

int main() {
  string o, e;
  cin >> o >> e;
  int n = e.size();
  for(int i=0; i<n; i++) {
    cout << o.at(i) << e.at(i);
  }
  if(o.size() > n) {
    cout << o.at(n) << endl;
  }
}