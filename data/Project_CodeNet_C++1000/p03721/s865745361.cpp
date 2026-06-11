#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=int64_t;
const int temp=1e5;
ll check[temp+1];

int main() {
  int N; ll K; cin >>N >>K;
  rep(i,0,N) {
    int a,b; cin >>a >>b;
    check[a]+=b;
  }
  rep_eq(ans,1,temp) {
    if (K<=check[ans]) {
      cout <<ans <<endl;
      break;
    }
    K-=check[ans];
  }
  return 0;
}
