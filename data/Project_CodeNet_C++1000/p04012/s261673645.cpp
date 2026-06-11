#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++) 
using namespace std;
typedef long long ll;

int main() {
  
  string s;
  cin >> s;
  
  bool ans = true;
  REP(i,s.size()) {
    int c = 0;
    REP(j,s.size()) {
      if (s[i] == s[j]) c++;
    }
    if (c % 2 != 0) {
      ans = false;
      break;
    }
  }
  
  cout << (ans ? "Yes" : "No") << endl;
  
}