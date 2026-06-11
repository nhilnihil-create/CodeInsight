#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string s;
  cin >> N >> s;
  int k = 0;
  int L = 0;
  int R = 0;
  int M = 0;
  for (int i = 0; i < N; i++) {
    if (s[i] == '(') {
      k++;
      L += 1;
    }
    if (s[i] == ')') {
      k--;
      R += 1;
    }
    M = min(M,k);
  }
  string sl, sr;
  for (int i = 0; i <-M; i++) {
    sl += '(';
  }
  for (int i = 0; i < L-M-R; i++) {
    sr += ')';
  }
  
  cout << sl << s << sr << endl;
}