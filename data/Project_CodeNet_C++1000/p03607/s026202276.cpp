#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  set<int> reg;
  vector<int> a(n);
  for(int i=0; i<n; i++) {
    cin >> a[i];
    auto c = reg.erase(a[i]);
    if(c==0) reg.insert(a[i]);
  }
  cout << reg.size() << endl;
  return 0;
}