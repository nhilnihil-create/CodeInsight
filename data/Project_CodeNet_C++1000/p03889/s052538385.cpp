#include <bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;

int main() {
  string S;
  cin >> S;

  string T = S;
  for(int i = 0; i < S.size(); i++) {
    if(S[i] == 'b') T[i] = 'd';
    else if(S[i] == 'd') T[i] = 'b';
    else if(S[i] == 'p') S[i] = 'q';
    else if(S[i] == 'q') S[i] = 'p';
  }
  reverse(begin(T), end(T));

  if(S == T) cout << "Yes" << endl;
  else cout << "No" << endl;
}