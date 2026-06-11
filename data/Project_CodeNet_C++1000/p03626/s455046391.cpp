#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int main() {
  int n, s;
  ll o;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  for(int i = 0; i < n; i++) {
    if(!i) {
      if(s1.at(i) == s2.at(i)) {
        o = 3;
        s = 1;
      } else {
        o = 6;
        s = 0;
        i++;
      }
    } else {
      if(s1.at(i) == s2.at(i)) {
        if(s)
          o *= 2;
        else
          s = 1;
      } else {
        if(s) {
          o *= 2;
          s = 0;
        } else
          o *= 3;
        i++;
      }
    }
    o %= MOD;
  }
  cout << o << endl;
}