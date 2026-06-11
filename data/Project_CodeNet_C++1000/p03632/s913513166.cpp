#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

int main() {
  int A,B,C,D; cin >>A >>B >>C >>D;
  int ST=max(A,C),ET=min(B,D);
  cout <<max(0,ET-ST) <<endl;
}
