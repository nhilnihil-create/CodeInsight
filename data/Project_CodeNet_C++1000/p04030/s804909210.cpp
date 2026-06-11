#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  string ans;

  for(char c:s) {
    if(c == 'B' && ans.size() >= 1) {
    ans.pop_back();
    } else if(c == '0' || c == '1'){
      ans.push_back(c);
    }
  }
  cout << ans << endl;
}