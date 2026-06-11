#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 
  
  string s;
  cin >> s;

  int count[26] = {0};

  for (char c: s) {
    count[c - 'a']++;
  }

  for (int i = 0; i < 26; ++i) {
    if (count[i] > 1) {
      cout << "no" << "\n";
      return 0;
    }
  }

  cout << "yes" << "\n";
}
