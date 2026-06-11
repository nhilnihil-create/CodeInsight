#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>

using namespace std;

int main() {
  int n;
  long ans = 1;
  cin >> n;

  for(int i = 2; i <= n; i++) {
    ans *= i;
    ans %= (1000000000+7);
  }
  cout << ans << endl;
}