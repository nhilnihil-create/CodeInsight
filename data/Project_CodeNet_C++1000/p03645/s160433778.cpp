#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=int64_t;

int main() {
  int N,M; cin >>N >>M;
  vector<bool> check(N);
  bool flag=false;
  rep(i,0,M) {
    int a,b; cin >>a >>b;
    if (a==1) {
      if (check[b-1]) flag=true;
      check[b-1]=true;
    }
    if (b==N) {
      if (check[a-1]) flag=true;
      check[a-1]=true;
    }
  }
  cout <<(flag ? "POSSIBLE":"IMPOSSIBLE") <<endl;
  return 0;
}
