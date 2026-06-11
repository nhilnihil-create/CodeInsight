#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++) 
using namespace std;

int main() {
  
  int a, b, c;
  cin >> a >> b >> c;
  
  int ans = 3;
  if (b == a) ans--;
  if (c == a || c == b) ans--;
  
  cout << ans << endl;

}