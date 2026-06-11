#include <bits/stdc++.h>
using namespace std;
bool even(string S, int l, int r) {
  for (int i = l; i+(r-l+1)/2 <= r; i++) {
    if (S[i] != S[i+(r-l+1)/2]) return false;
  }
  return true;
}
int main() {
  string S;
  int answer=0;
  cin >> S;
  for (int i = 0; i < S.length(); i++) {
    for (int j = S.length()-1; j > i; j--) {
      if ((j-i)%2 && j-i != S.length()-1 && even(S,i,j)) {
        answer=max(answer,j-i+1); 
      }
    }
  }
  cout << answer;
}