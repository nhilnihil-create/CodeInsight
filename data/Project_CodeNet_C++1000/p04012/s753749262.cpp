#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  cin >> S;
  int N = S.size();
  vector<int> count(26, 0); 
  for(int i = 0; i < N; i++) {
    int n = S[i] - 'a';
    count[n]++;
  }
  bool finished = false;
  for(int i = 0; i < 26; i++) {
    if(count[i] % 2 == 1) {
      finished = true;
      break;
    }
  }
  if(finished) {
    cout << "No" << endl;
  }
  else {
    cout << "Yes" << endl;
  }
}