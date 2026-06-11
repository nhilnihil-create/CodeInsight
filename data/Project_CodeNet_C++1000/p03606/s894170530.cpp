#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n, l, r, k;
  cin >> n;
  for (int i=1;i<=n;i++) {
    cin >> l >> r;
    k += r-l+1;
  } 
  cout << k << endl; 
}