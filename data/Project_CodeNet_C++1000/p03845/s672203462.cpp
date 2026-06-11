#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

int main() {
  int N; cin >>N;
  vector<int> T(N);
  rep(i,0,N) cin >>T[i];
  vector<int> Copy(T.size());
  int M; cin >>M;
  rep(i,0,M) {
    int P,X; cin >>P >>X;
    copy(T.begin(),T.end(),Copy.begin());
    Copy[P-1]=X;
    int sum=accumulate(Copy.begin(),Copy.end(),0);
    cout <<sum <<endl;
  }
  return 0;
}
