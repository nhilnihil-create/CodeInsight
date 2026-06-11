#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++) 
using namespace std;
typedef long long ll;

int main() {
  
  string s;
  cin >> s;
  
  bool ans = true;
  REP(i,s.size()) {
    REP(j,s.size()-i) {
      if (s[i] == s[i+j+1]) ans = false;
    }
  }
  
  cout << (ans ? "yes" : "no") << endl;
  
}