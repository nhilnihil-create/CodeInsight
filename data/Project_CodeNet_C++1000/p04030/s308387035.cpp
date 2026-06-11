#include<bits/stdc++.h>
using namespace std;
int main () {
  char S[100];
  int si = 0;
  string com;
  cin >> com;
  for (int i = 0; i < (int)com.size(); i ++) {
    char c = com[i];
    if (c == '0') {
      S[si] = '0';
      si ++;
    }
    if (c == '1') {
      S[si] = '1';
      si ++;
    }
    if (c == 'B') {
      si = max(si - 1, 0);
    }
  }
  for (int i = 0; i < si; i ++) {
    cout << S[i];
  }
  cout << endl;
}
