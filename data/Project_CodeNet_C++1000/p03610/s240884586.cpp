#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++) 
using namespace std;
typedef long long ll;

int main() {
  
  string s;
  cin >> s;
  
  REP(i,s.size()) {
    if (i % 2 == 0) cout << s[i];
  }
  
}