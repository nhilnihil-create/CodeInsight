#include <bits/stdc++.h>
#define rep(i,m,n) for(int i=m; i<n; i++)
#define co(n) cout << n << endl
using namespace std;
int main(){
  string s;
  cin >> s;
  int c=0, d=0;
  if(s.size()<4) co("No");
  else if(s.at(0)=='Y' && s.at(1)=='A' && s.at(2)=='K' && s.at(3)=='I') co("Yes");
  else co("No");
  
  return 0;
}
