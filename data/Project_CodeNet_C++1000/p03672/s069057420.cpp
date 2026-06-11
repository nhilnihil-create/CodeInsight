#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s;
  cin >> s;
  
  for (int i = s.length()-2; i >= 2; i -= 2) {
    vector<char> zen(i/2), kou(i/2);
    for (int j = 0; j < i; j++) {
      if (j < i/2)
        zen[j] = s[j];
      else
        kou[j - i/2] = s[j];
    }
    bool check = true;
    for (int j = 0; j < i/2; j++) {
      if (zen[j]!=kou[j]) {
        check = false;
        break;
      }
    }
    if (check) {
      cout << i;
      break;
    }
  }
}