#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

int main() {
  int n;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;

  long long ans = 1;
  int prev = -1;
  for(int i=0;i<n;i++) {
    if(s1[i] == s2[i]) {
      if(prev == -1) ans *= 3;
      else if(prev == 1) ans = ans * 2 % mod;

      prev = 1;
    }
    else {
      if(prev == -1) ans *= 6;
      else if(prev == 1) ans = ans * 2 % mod;
      else if(prev == 2) ans = ans * 3 % mod;

      prev = 2;
      i++;
    }
  }

  cout << ans << endl;
}