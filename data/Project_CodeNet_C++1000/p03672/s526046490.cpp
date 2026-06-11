#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  for (int i = s.size()/2-1; i>0; i--) {
    if (s.substr(0,i) == s.substr(i,i)) {
      cout << i * 2 << endl;
      return 0;
    }
  }
}
