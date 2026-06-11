#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
int main(){
  int h, w;
  cin >> h >> w;
  string s, alf;
  rep (i, w+2) s += '#';
  cout << s << endl;
  rep (i, h) {
    cin >> alf;
    cout << '#' + alf + '#' << endl;
  }
  cout << s << endl;
}

