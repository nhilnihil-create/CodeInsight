#include <bits/stdc++.h>
using namespace std;

int main () {
  string s,t,u;
  cin >> s >> t >> u;
  char dif='A'-'a';

  char xs,xt,xu;
  xs=s[0]+dif;
  xt=t[0]+dif;
  xu=u[0]+dif;

  cout << xs << xt << xu << endl;

  return 0;
}
