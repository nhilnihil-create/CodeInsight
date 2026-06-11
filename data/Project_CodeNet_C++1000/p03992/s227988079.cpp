#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  
  for (int i = 0; i < 4; i++) {
    cout << S.at(i);
  }
  cout << ' ';
  for (int i = 0; i < 8; i++) {
    cout << S.at(i+4);
  }
  cout << endl;
}