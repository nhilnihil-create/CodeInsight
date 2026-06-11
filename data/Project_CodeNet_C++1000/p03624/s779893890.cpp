#include<bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  
  bitset<26> b;
  for (char c: S) b.set(c - 'a');

  for (int i = 0; i < 26; i++) {
    if (!b.test(i)) {
      cout << (char)('a' + i) << endl;
      return 0;
    }
  }
  
  cout << "None" << endl;
}
