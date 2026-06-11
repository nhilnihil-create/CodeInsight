#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  sort(s.begin(), s.end());

  if(s.size()%2 == 1) {
    cout << "No" << endl;
  }
  else {
    bool btf = true;
    for(int i=1; i<s.size(); i+=2) {
      if(s[i]!=s[i-1]) {
        btf = false;
        break;
      } 
    }
    if(btf) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}