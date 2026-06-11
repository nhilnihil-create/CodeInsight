#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  string S, T;
  int ans=0;
  cin >> S;
  T="CODEFESTIVAL2016";
  for (int i=0; i<16; i++) {
    if (S.at(i)!=T.at(i)) {
      ans=ans+1;
    }
  }
  cout << ans << endl;
}
