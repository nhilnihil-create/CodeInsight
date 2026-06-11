#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  cin >> S;
  int N = S.size();
  bool finished = false;
  for(int i = 0; i < N - 1; i++) {
    for(int j = i + 1; j < N; j++) {
      if(S.at(i) == S.at(j)) {
        finished = true;
        break;
      }
    }
    if(finished) {
      break;
    }
  }
  if(finished) {
    cout << "no" << endl;
  }
  else {
    cout << "yes" << endl;
  }
}