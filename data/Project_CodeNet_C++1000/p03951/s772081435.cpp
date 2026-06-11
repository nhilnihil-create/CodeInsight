#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string s, t;
  cin >> N >> s >> t;
  
  int x = N;
  for (int i = 0; i < N; i++) {
    string S, T;
    S = s.substr(i);
    T = t.substr(0,N-i);
    if (S == T) {
      x = i;
      break;
    }
  }
  
  cout << N + x << endl;
}