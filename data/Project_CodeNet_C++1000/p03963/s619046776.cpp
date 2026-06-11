#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  long ans = k;

  for(int i = 1; i < n; i++)
    ans *= k-1;
  
  cout << ans << endl;
}