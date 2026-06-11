#include <bits/stdc++.h>
typedef long long LL;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

using namespace std;

int main(void)
{
  int n;
  string s;
  cin >> n >> s;
  string tmp[4]={"SS","SW","WS","WW"};

  REP(i,4) {
    FOR(j,2,n) {
      if((s[j-1] == 'o') ^ (tmp[i][j-1] == 'S') ^ (tmp[i][j-2] == 'S')) {
        tmp[i].push_back('S');
      } else {
        tmp[i].push_back('W');
      }
    }
  }

  REP(i,4) {
    if(((s[n-1] == 'o') ^ (tmp[i][n-1] == 'S') ^ (tmp[i][n-2] == 'S') ^ (tmp[i][0] == 'S'))
       || ((s[0] == 'o') ^ (tmp[i][0] == 'S') ^ (tmp[i][n-1] == 'S') ^ (tmp[i][1] == 'S')))
      continue;
    else {
      cout << tmp[i] << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
