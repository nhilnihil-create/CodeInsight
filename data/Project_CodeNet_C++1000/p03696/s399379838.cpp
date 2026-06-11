#include<bits/stdc++.h>
using namespace std;
int main () {
  int N;
  cin >> N;
  int on = 0;
  int af = 0;
  string S;
  cin >> S;
  int kj = 0;
  for (int i = 0; i < N; i ++) {
    if (S[i] == '(') {
      kj --;
    }
    else {
      kj ++;
      if (kj == 1) {
        on ++;
        kj = 0;
      }
    }
  }
  kj = 0;
  for (int i = N - 1; i >= 0; i --) {
    if (S[i] == ')') {
      kj --;
    }
    else {
      kj ++;
      if (kj == 1) {
        af ++;
        kj = 0;
      }
    }
  }
  for (int i = 0; i < on; i ++) cout << '(';
  cout << S;
  for (int i = 0; i < af; i ++) cout << ')';
  cout << endl;
}

