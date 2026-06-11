#include <bits/stdc++.h>
using namespace std;

int main () {
  string A;
  cin >> A;
  int N = A.size();
  A += "00";
  vector<bool> alph(26,false);
  vector<int> ansl(N+2,1);
  int amount = 26;
  int s;
  for (int i=N-1; i>=0; i--) {
    s = A[i] - 'a';
    ansl[i] = ansl[i+1];
    if (!(alph[s])) {
      amount--;
      alph[s] = true;
      if (amount == 0) {
        ansl[i]++;
        amount = 26;
        for (int i=0; i<26; i++) {
          alph[i] = false;
        }
      }
    }
  }
  for (int i=0; i<26; i++) {
    alph[i] = false;
  }
  int now = ansl[0];
  cerr << now << endl;
  char c;
  ansl[N] = 0;
  ansl[N+1] = 0;
  for (int i=0; i<N; i++) {
    if (now == ansl[i+1]) {
      s = A[i] - 'a';
      alph[s] = true;
    }
    else {
      now--;
      for (int j=0; j<26; j++) {
        if (alph[j] == false) {
          c = 'a' + j;
          cout << c;
          break;
        }
      }
      for (int j=0; j<26; j++) {
        alph[j] = false;
      }
      if (now == 0) {
        break;
      }
      for (;;) {
        if (A[i] == c) {
          break;
        }
        else {
          i++;
        }
      }
    }
  }
  for (int i=0; i<N+1; i++) {
    cerr << ansl[i];
  }
  cerr << endl;
  for (int i=0; i<N+1; i++) {
    cerr << A[i];
  }
  cerr << endl;
  cout << endl;
}