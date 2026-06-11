#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <math.h>
#include <stack>
#include <string>
#include <string.h>
using namespace std;
double PI = 3.1415926535897932;
long mod = 1000000007;

int main() {
  int n, s[200];
  cin >> n;
  int sum = 0;
  for(int i = 0; i < n; i++) {
    cin >> s[i];
    sum += s[i];
  }
  sort(s,s+n);
  
  for(int i = 0; i < n; i++) {
    if(sum % 10 == 0) {
      if(s[i] % 10 != 0) {
        sum -= s[i];
        cout << sum << endl;
        return 0;
      }
    }
    else {
      cout << sum << endl;
      return 0;
    }
  }
  cout << 0 << endl;
}
