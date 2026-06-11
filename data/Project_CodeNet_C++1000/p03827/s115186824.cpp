#include <bits/stdc++.h>
using namespace std;

void chmax(int& a, int b) {
  if (a < b) a = b;
}

int main() {
  int N;
  cin >> N;
  
  string S;
  cin >> S;
  
  int x = 0;
  int ans = 0;
  for (int i = 0; i < S.size(); i++) {
    if (S[i] == 'I') {
      x++;
    } else {
      x--;
    }
    
    chmax(ans, x);
  }
  
  cout << ans << endl;
}