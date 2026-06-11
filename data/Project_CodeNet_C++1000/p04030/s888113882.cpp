#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  vector<char> v;
  string s;
  cin >> s;

  for (char c: s) {
    if (c != 'B') v.emplace_back(c);
    else if (!v.empty()) v.pop_back();
  }

  string res(begin(v), end(v));
  cout << res << "\n";
}
