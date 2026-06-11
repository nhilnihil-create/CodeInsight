#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=int64_t;

int main() {
  int N; cin >>N;
  int hairetsu=1e5+2;
  vector<int> check(hairetsu);
  rep(i,0,N) {
    int a; cin >>a;
    check[a  ]++;
    check[a+1]++;
    check[a+2]++;
  }
  int ans=0;
  rep(i,0,hairetsu) ans=max(ans,check[i]);
  cout <<ans <<endl;
  return 0;
}
