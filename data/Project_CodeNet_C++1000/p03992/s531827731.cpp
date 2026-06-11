#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0; i < (n); ++i)
#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)

using ll = long long;
#define INF 1e9

int main(){
  string s;
  cin >> s;
  REP(i, 4){
    cout << s[i];
  }
  cout << " ";
  FOR(i, 4, 12){
    cout << s[i];
  }
  cout << endl;
  return 0;
}
