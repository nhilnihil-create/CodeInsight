#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  
  vector<int> edit;
  
  for (int i = 0; i < S.size(); i++) {
    if (S[i] == '0') {
      edit.push_back(0);
    } else if (S[i] == '1') {
      edit.push_back(1);
    } else {
      if (edit.size()) edit.pop_back();
    }
  }
  
  for (int i = 0; i < edit.size(); i++) {
    cout << edit[i];
  }
  cout << endl;
}