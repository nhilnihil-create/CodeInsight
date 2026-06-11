#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int n, l;
  cin >> n >> l;

  vector<string> v;

  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    v.emplace_back(s);
  }

  sort(begin(v), end(v));
    
  string res;
  for (string s: v) res += s;
  cout << res << "\n";
}
