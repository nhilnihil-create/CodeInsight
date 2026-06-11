#include <bits/stdc++.h>
using namespace std;

int main () {
  string s; cin >> s;
  int N = s.size();
  int S =0, F =0;
  for (int i =0; i<N; i++) {
    if (s[i] == 'A') {
      S = i; break;
    }
  }
  for (int i =N-1; i>0; i--) {
    if (s[i] == 'Z') {
      F = i; break;
    }
  }
  
  cout << F - S + 1 << endl;
        
}                                                