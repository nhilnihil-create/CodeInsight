#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  
  vector<int> moji(26, 0);
  
  for (int i = 0; i < S.size(); i++) {
    moji[S[i] - 'a']++;
  }
  
  for (int i = 0; i < 26; i++) {
    if (moji[i] != 0 && moji[i] != 1) {
      cout << "no" << endl;
      return 0;
    } 
  }
  
  cout << "yes" << endl;
  
}