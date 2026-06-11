#include <bits/stdc++.h>
using namespace std;

int main () {
  int N;
  string s,t;
  cin >> N >> s >> t;
  
  for (int i = 0; i < N; i++) {
    int ans = N * 2;
    for (int j = 0; j < N-i; j++) {
      if (t.at(j) == s.at(i+j)){
        ans--;
        if (j == N-i-1){
          cout << ans << endl;
          return 0;
        }
      }
      else {
        break;
      }
    }
  }
  cout << N*2 << endl;
}
  