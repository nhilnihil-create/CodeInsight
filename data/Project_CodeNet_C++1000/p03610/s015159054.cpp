#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  string S;
  cin >> S;
  int s=S.size();
  if (s==1||s==2) {
    cout << S.at(0) << endl;
  }
  else {
    if (s%2==0) {
      for (int i=0; i<s/2-1; i++) {
        cout << S.at(2*i);
      }
      cout << S.at(s-2) << endl;
    }
    else {
      for (int j=0; j<(s-1)/2; j++) {
        cout << S.at(2*j);
      }
      cout << S.at(s-1) << endl;
    }
  }
}