#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

int main() {
  int N; cin >>N;
  int hairetsu=1e9+1;
  vector<bool> check(hairetsu);
  rep(i,0,N) {
    int A; cin >>A;
    if (check[A]) check[A]=false;
    else check[A]=true;
  }
  int ans=0;
  rep(i,0,check.size()) {
    if (check[i]) ans++;
  }
  cout <<ans <<endl;
  return 0;
}
