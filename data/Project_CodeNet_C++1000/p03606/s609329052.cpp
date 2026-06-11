#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, v;
  bool y = false;
  cin >> n;  
  for (int i = 0; i < n; i++) {    
  	int l, r;
    cin >> l >> r;
    v += r - l + 1;
  }
  cout << v << endl;
}
