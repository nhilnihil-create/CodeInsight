#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  int s;
  vector<int> b;
for (int i = 0; i < n; i++) {
  cin >> a.at(i);
  if (a.at(i) == i + 1){s++;}
  else{b.push_back(s);
       s = 0;}
}
  b.push_back(s);
  int r;
  r = b.size();
  int m = 0;
  for (int i = 0; i < r; i++) {
    m += (b.at(i) + 1) / 2;
  }
  cout << m << endl;
}