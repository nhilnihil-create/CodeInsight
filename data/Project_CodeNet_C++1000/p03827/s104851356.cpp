#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;

  int x = 0, max_x = 0;

  for(int i=0; i < N; i++) {
    if(S[i] == 'I') {
      x++;
      max_x = max(max_x, x);
    }else if(S[i] == 'D') {
      x--;
    }
  }
  cout << max_x << endl;
}

