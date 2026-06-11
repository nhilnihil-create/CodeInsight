#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

int main(){
  int A,B; cin >>A >>B;
  if (A==1) A=14;
  if (B==1) B=14;

  if (A>B) cout <<"Alice" <<endl;
  else if (A<B) cout <<"Bob" <<endl;
  else cout <<"Draw" <<endl;
}
