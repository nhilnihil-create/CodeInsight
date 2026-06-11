#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  for(int i=1; i<=b; i++) {
    if(i*a%b==c) {
      cout << "YES" << endl;
      break;
    }
    if(i==b) {
      cout << "NO" << endl;
      break;
    }
  }
  return 0;
}