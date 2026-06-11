#include <bits/stdc++.h>
#include<chrono>
using namespace std;
using ll = long long;

int main() {
  int N;
  string s, t;
  cin >> N >> s >> t;
  //iはtとsの重複した長さ
  for (int i = N; i >= 1; i--) {
    bool check = true;
    for (int j = 0; j < i; j++) {
      if (s[N-i+j] != t[j]) {
        check = false;
      }
    }
    if (check) {
      cout << 2*N-i << endl;
      return 0;
    }
  }
  cout << 2*N << endl;
}
