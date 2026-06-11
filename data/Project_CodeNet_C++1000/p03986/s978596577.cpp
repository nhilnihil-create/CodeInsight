#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  
  int N = S.size();
  
  int s = 0, t = 0;
  
  for (int i = 0; i < N; i++) {
    if (S[i] == 'S') s++;
    if (S[i] == 'T') {
      if (s > 0) {
        s--;
      } else {
        t++;
      }
    }
  }
  
  cout << s + t << endl;
}