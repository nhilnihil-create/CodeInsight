#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>

using namespace std;

int main() {
  int n, a[110000],ans = 1, flag = 0;
  cin >> n;

  for(int i = 1; i <= n; i++)
    cin >> a[i];

  int x = a[1];
  for(int i = 0; i < n; i++) {
    if(x == 2) {
      flag = 1;
      break;
    }
    x = a[x];
    ans++;
  }
  if(flag) cout << ans << endl;
  else cout << "-1" << endl;
}