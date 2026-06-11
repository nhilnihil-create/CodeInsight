#include<bits/stdc++.h>
using namespace std;
int main () {
  string S;
  cin >> S;
  int n = (int)S.size();
  int dif = 0;
  for (int i = 1; i < n; i ++) {
    if (S[i - 1] != S[i]) dif ++;
  }
  cout << dif << endl;
}