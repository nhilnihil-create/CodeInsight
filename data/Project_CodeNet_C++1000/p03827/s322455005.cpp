#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  string S;
  cin >> N >> S;
  int count = 0;
  int ans = 0;
  for(int i = 0; i < N; i++) {
    if(S.at(i) == 'I') {
      count++;
    }
    else {
      count--;
    }
    if(count > ans) {
      ans = count;
    }
  }
  cout << ans << endl;
}