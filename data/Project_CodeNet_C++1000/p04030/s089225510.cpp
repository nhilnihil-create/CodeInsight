#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  string s;
  cin >> s;

  int n = s.size();
  vector<char> v;
  for (int i = 0; i < n; i++) {
    char c = s[i];
    if(c == '0') v.push_back('0');
    else if(c == '1') v.push_back('1');
    else if(c == 'B' && !v.empty()) v.pop_back();
  }

  while(!v.empty()) {
    char c = v.front();
    v.erase(v.begin());
    cout << c;
  }
  cout << endl;

  return 0;
}