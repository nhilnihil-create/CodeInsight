#include<bits/stdc++.h>
using namespace std;
int main () {
  string S;
  cin >> S;
  int N = (int)S.size();
  int kj = N / 2;
  int ans = 0;
  for (int i = 0; i < N; i ++) {
    if (S[i] == 'p') ans ++;
  }
  cout << kj - ans << endl;
}