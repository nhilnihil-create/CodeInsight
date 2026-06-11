#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >>n;
  
  int ans = 1, countans = 0;
  
  for (int i = 1; i <= n; i++) {
    int a = i;
    int counta = 0;
    while (a % 2 == 0) {
      counta ++;
      a /= 2;
    }
    if (counta > countans) {
      ans = i;
      countans = counta;
    }
  }
  cout << ans;
}