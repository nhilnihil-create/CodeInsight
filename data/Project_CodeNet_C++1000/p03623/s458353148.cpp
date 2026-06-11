#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++) 
using namespace std;

int main() {
  
  int x, a, b;
  cin >> x >> a >> b;
  
  int xa = max(x-a,a-x);
  int xb = max(x-b,b-x);
  
  cout << ((xa > xb) ? "B" : "A") << endl;
}