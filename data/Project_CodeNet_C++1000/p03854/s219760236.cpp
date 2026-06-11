#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  string s;
  cin >> s;

  reverse(begin(s), end(s));
  while (s.size() > 0) {
    if (s.substr(0, 5) == "maerd") s = s.substr(5);
    else if (s.substr(0, 7) == "remaerd") s = s.substr(7);
    else if (s.substr(0, 5) == "esare") s = s.substr(5);
    else if (s.substr(0, 6) == "resare") s = s.substr(6);
    else break;
  }

  if (s.size() == 0) cout << "YES" << "\n";
  else cout << "NO" << "\n";

}
