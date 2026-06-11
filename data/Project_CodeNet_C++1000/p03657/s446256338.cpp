#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

int main() {
  int A,B; cin >>A >>B;
  bool flag=false;
  if (  (A+B)%3==0
      || A%3==0
      || B%3==0   ) flag=true;
  if (flag) cout <<"Possible" <<endl;
  else cout << "Impossible" << endl;
  return 0;
}
