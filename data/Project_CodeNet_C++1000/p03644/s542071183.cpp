#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  
  int x, max, ans;
  int count = 0;
  for(int i=1; i<=n; i++) {
    x = i;
    while(true) {
      if(x%2==0) {
        count++;
        x /= 2;
      }
      else if(count>=max) {
        ans = i;
        max = count;
        break;
      }
      else break;
    }
    count = 0;
  }
  cout << ans << endl;
  return 0;
}