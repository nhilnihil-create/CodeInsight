#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i=0; i<n; i++) {
    cin >> p.at(i);
  }
  
  vector<int> pla(n);
  for (int i=0; i<n; i++) {
    pla.at(p.at(i)-1) = i+1;
  }
  
  vector<long long> a(n), b(n);
  for (int i=0; i<n; i++) {
    a.at(i) = 20000 * (i+1);
    b.at(i) = 20000 * (n-i) + pla.at(i);
  }
  
  for (int i=0; i<n; i++) {
    cout << a.at(i);
    if (i == n-1) cout << endl;
    else cout << ' ';
  }
  for (int i=0; i<n; i++) {
    cout << b.at(i);
    if (i == n-1) cout << endl;
    else cout << ' ';
  }
  
  return 0;
}
