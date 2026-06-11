#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  
  int a, b;
  int ans = 0;
  for(int i=0; i<n; i++) {
    cin >> a >> b;
    ans += b-a+1;
  }
  cout << ans << endl;
  return 0;
}