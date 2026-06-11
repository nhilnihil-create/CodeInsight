#include <bits/stdc++.h>
#define rep(i,m,n) for(int i=m; i<n; i++)
#define co(n) cout << n << endl
using namespace std;
int main(){
  string s, a="CODEFESTIVAL2016";
  cin >> s;
  int c=0;
  rep(i,0,16){
    if(s.at(i)!=a.at(i)) c++;
  }
  co(c);

  return 0;
}
