#include <bits/stdc++.h>
using namespace std;

int main() {
  string w; cin >> w;
  int N = w.size();
  if (N % 2 == 1) {
    cout << "No" << endl;
  } else {
    vector<int> alp(26,0);
    for (int i =0; i<N; i++) {
      for (int j =0; j<26; j++) {
        if (w[i] == 'a' + j) alp[j]++;
      }
    }
    bool check = true;
    for (int i =0; i<26; i++) {
      if (alp[i] % 2 == 1) {
        check = false; break;
      }
    }
    if (check) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}