#include <bits/stdc++.h>
using namespace std;

int main() {
  string w;
  cin >> w;
  bool even = true;

  for(char c = 'a'; c <= 'z'; c++) {
    int cnt = 0;
    for(int i=0; i < w.size(); i++) {
      if(w[i] == c) {
        cnt++;
      }
    }
    if(cnt % 2 == 1){
      even = false;
      break;
    }
  }
  cout << (even ? "Yes" : "No") << endl;
}