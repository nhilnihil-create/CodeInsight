#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  int N, K;
  cin >> s >> K;
  N = s.size();
  int ct = 0;
  for (int i = 0; i < N; i++) {
    if (s[i] == 'a') continue;
    int p = 'z'-s[i]+1;
    if (p + ct <= K) {
      s[i] = 'a';
      ct += p;
    }
  }
  int q = (K-ct)%26;
  for (int i = 0; i < q; i++) {
    if (s[N-1] == 'z') s[N-1] = 'a';
    else s[N-1] = s[N-1] + 1;
  }
  cout << s << endl;
}