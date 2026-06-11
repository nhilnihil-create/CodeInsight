#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  string s;
  cin >> n >> s;
  
  int ans = 0;
  int x = 0;
  for(int i=0; i<s.size(); i++) {
    if(s[i]=='I') x++;
    else x--;
    if(x>ans) ans = x;
  }
  cout << ans << endl;
}