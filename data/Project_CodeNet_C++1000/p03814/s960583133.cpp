#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int ai=S.size(), zi=0;
  for (int i=0; i<S.size(); i++) {
    if (S[i]=='A') {
      ai=min(ai, i);
    }
    if (S[i]=='Z') {
      zi=max(zi, i);
    }
  }
  cout << zi-ai+1 << endl;
}