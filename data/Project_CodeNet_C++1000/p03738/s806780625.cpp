#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=int64_t;

int main(){
  string A,B; cin >>A >>B;
  ll temp1=A.size(),temp2=B.size();

  if (temp1>temp2) cout <<"GREATER" <<endl;
  else if (temp1<temp2) cout <<"LESS" <<endl;
  else if (temp1==temp2) {
    if (A>B) cout <<"GREATER" <<endl;
    else if (A<B) cout <<"LESS" <<endl;
    else cout <<"EQUAL" <<endl;
  }
  return 0;
}
