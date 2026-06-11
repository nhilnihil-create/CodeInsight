#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  string s; cin >> s;

  string res;
  for (int i = 0; i < s.size(); i += 2) {
    res += s[i];
  }

  cout << res << "\n";
}
