#include<bits/stdc++.h>
using namespace std;
int main () {
  string S;
  cin >> S;
  int N = (int)S.size();
  for (int i = 0; i < N - 1; i ++) {
    if (S[i] == S[i + 1]) {
      cout << i + 1 << ' ' << i + 2 << endl;
      return 0;
    }
    if (i + 2 < N && S[i] == S[i + 2]) {
      cout << i + 1 << ' ' << i + 3 << endl;
      return 0;
    }
  }
  cout << "-1 -1" << endl;
}