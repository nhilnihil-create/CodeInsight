#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  
  cout << S[0];
  
  for (int i = 2; i < S.size(); i++) {
    if (i % 2 == 0) {
      cout << S[i];
    }
  }
  
  cout << endl;
}