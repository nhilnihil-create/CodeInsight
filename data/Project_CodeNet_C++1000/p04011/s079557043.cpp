#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using vi=vector<int>;
using vvi=vector<vi>;
using ll=long long;

int main() {
  int N,K,X,Y; cin >>N >>K >>X >>Y;
  int ans;
  if (N>K) {
    ans=X*K+Y*(N-K);
  } else {
    ans=X*N;
  }
  cout <<ans <<endl;
  return 0;
}
