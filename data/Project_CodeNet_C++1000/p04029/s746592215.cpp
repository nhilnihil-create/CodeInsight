#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  int ans = 0;
  cin >> n;   
  for (int i = 0; i <= n; i++ ) {
    ans = ans + i;
  }
  cout << ans << endl;
}