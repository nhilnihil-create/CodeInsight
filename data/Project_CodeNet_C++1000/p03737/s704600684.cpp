#include <bits/stdc++.h>
using namespace std;

int main(){
  string a,b,c;
  cin >> a >> b >> c;
  string ans="";
  ans+=toupper(a.front());
  ans+=toupper(b.front());
  ans+=toupper(c.front());
  cout << ans << endl;
  return 0;
}
