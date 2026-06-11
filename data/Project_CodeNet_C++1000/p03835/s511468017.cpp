#include <bits/stdc++.h>
using namespace std;

int main() {
  int k,s,ans=0;
  cin >> k >> s;
  
  for (int x=0; x < k+1; x++) {
    if (s-x>2*k) continue;
    else if (s-x<0) continue;
    else {
      ans += min((2*k+1)-(s-x),s-x+1);
    }
  }
  cout << ans << endl;
}