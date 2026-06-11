#include<bits/stdc++.h>
using namespace std;
int main () {
  string S;
  cin >> S;
  int N = (int)S.size();
  int ans = 0;
  int b = 0;
  for (int i = 0; i < N; i ++) {
    if (S[i] == 'S') b ++;
    else {
      if (b == 0) ans ++;
      else b --;
    }
  }
  cout << ans * 2 << endl;
}
