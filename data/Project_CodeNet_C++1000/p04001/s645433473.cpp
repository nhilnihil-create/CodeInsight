#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <math.h>
#include <stack>
#include <string>
#include <string.h>
using namespace std;
const double PI = acos(-1.0);
const long mod = 1000000007;
const long INF = 1e9 + 1;

int main() { 
  string s;
  cin >> s;
  int n = s.size();
  if(n == 1) {
    cout << s << endl;
    return 0;
  }
  long sum = 0;

  for(int bit = 0; bit < (1 << n-1); bit++) {
    int cnt = 0;
    for(int i = 0; i < n-1; i++) {
      sum += (s[n-1-i] - '0') * pow(10,cnt);
      if(bit & (1 << i)) {
        cnt = 0;
        if(i == n-2) sum += (s[0] - '0');
      }
      else {
        cnt++;
        if(i == n-2) sum += (s[0] - '0') * pow(10,cnt);
      }
    }
  }
  
  cout << sum << endl;
}
