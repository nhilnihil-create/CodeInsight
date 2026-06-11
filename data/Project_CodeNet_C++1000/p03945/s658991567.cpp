#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main(void) {
  string s;
  cin >> s;

int cnt = 0;
  rep(i,s.size()) {
    if (i == s.size()-1) ;
    else if(s[i] != s[i+1]) cnt++;
    else ;
  }
  cout << cnt << endl;
}