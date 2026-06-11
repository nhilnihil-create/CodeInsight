#include <bits/stdc++.h>
using namespace std;

int main() {
  string w;
  cin >> w;
    
  vector<int> count(30, 0);
  
  for (int i = 0; i < w.size(); i++) {
    count[w[i] - 'a']++;
  }
  
  bool cond = true;
  for (int i = 0; i < 26; i++) {
    if (count[w[i]-'a'] % 2 == 1) {
      cond = false;
      break;
    }
  }
  
  if (cond) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  
  
}


