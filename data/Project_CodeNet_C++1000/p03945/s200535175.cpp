#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using ld = long double;

int main(){
  string s; cin >> s;
  char tmp = s[0];
  int count = 0;
  for(char k : s) {
    if(tmp != k) {
      count++;
      tmp = k;
    }
  }

  cout << count << endl;
}

