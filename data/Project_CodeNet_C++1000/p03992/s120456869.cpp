#include <bits/stdc++.h>
#define rep(i,m,n) for(int i=m; i<n; i++)
#define co(n) cout << n << endl
using namespace std;
int main(){
  string s;
  cin >> s;
  rep(i,0,4) cout << s.at(i);
  cout << " ";
  rep(i,4,12) cout << s.at(i);
  cout << endl;

  return 0;
}
