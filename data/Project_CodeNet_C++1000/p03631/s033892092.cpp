#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

int main() {
  string N; cin >>N;
  bool flag=false;
  if (N[0]==N[2]) flag=true;
  cout <<(flag ? "Yes":"No") <<endl;
  return 0;
}
