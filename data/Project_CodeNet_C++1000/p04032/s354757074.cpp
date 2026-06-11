#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  pair<int, int> ans = make_pair(-1, -1);

  for(int i=0;i<s.size()-1;i++) {
    if(s[i] == s[i+1]) {
      ans.first = i+1;
      ans.second = i+2;
      break;
    }
  }

  for(int i=0;i<s.size()-2;i++) {
    if(s[i] == s[i+2]) {
      ans.first = i+1;
      ans.second = i+3;
      break;
    }
  }

  cout << ans.first << " " << ans.second << endl;
}