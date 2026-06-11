#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  string ans = "NO";
  for(int i = 1; i <= b; i++) {
    if(a * i % b == c) {
      ans = "YES";
      break;
    }
  }
  cout << ans;
}