#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

int main(){
  string A,B,C; cin >>A >>B >>C;
  bool flag=false;
  if (A.back()==B.front() && B.back()==C.front()) flag=true;
  cout <<(flag ? "YES":"NO") <<endl;
  return 0;
}
