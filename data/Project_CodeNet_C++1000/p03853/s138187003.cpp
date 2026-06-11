#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int a, b;
  cin >> a >> b;
  string s;
  vector<vector<char>> v(a*2, vector<char>(b));
  for(int i=0; i<a; i++) {
    cin >> s;
    for(int j=0; j<b; j++) {
      for(int k=2*i; k<2*i+2; k++) {
        v[k][j] = s[j];
      }
    }
  }
  
  for(int i=0; i<a*2; i++) {
    for(int j=0; j<b; j++) {
      cout << v[i][j];
      if(j==b-1) cout << endl;
    }
  }
  return 0;
}