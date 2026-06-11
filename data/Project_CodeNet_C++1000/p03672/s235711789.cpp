#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 
  
  string s;
  cin >> s;

  int n = s.size();

  for (int i = n - 2; i > 0; i -= 2) {
    if (s.substr(0, i / 2) == s.substr(i / 2, i / 2)) {
      cout << i << "\n";
      return 0;
    }
  } 
}
