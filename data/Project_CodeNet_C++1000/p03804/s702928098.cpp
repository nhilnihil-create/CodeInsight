#include <bits/stdc++.h>
#define rep(i,n) for (int i =0; (int)i<n; i++) 
using namespace std;
 
int main(){
  int N,M; cin >> N >> M; char A[N][N],B[M][M];
  rep(i,N) rep(j,N) cin >> A[i][j];
  rep(i,M) rep(j,M) cin >> B[i][j];
  bool check = false;
  rep(i,N-M+1) rep(j,N-M+1) {
      rep(k,M) rep(l,M) if (B[k][l] != A[i+k][j+l]) goto fail; 
      check = true; goto pass; fail:;
  }
  pass: if (check) cout << "Yes" << endl;
  else cout << "No" << endl;}