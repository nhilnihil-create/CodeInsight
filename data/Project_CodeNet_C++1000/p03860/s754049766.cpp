#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  string res;

  for (int i = 0; i < 3; ++i) {
    string s; cin >> s;
    res += toupper(s[0]);
  }
  cout << res << "\n";
}
