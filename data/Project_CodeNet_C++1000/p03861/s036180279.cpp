#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>

using namespace std;

long x;

long f(long n) {
  if(n >= 0)
    return n/x + 1;
  else return 0;
}

int main() {
  long a,b, ans;
  cin >> a >> b >> x;

  ans = f(b) - f(a-1);

  cout << ans << endl;
}