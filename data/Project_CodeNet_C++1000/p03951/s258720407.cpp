#include<bits/stdc++.h>
using namespace std;

int main() {
  long long N;
  string s,t;
  cin >> N >> s >> t;
  
  for (int i=N; i>=1; i--) {
    for (int j=0; j<i; j++) {
      if (s[N-i+j] != t[j]) break;
      if (j == i-1) {
        cout << N*2-i << endl;
        return 0;
      }
    }
  }
  
  cout << N*2 << endl;
}