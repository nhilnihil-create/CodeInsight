#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int (i)=0; (i)<(n); (i)++) 
using LL = long long;

const LL MOD = 1e9+7;
 
int N;
int A[114514];
int T[114514];
int L[114514];
int R[114514];

int main() {
  scanf("%d", &N);
  rep(i, N) {
    scanf("%d", &T[i+1]);
  }
  rep(i, N) {
    scanf("%d", &A[i+1]);
  }
  rep(i, N) {
    if (T[i] < T[i+1]) {
      R[i+1] = L[i+1] = T[i+1];
    } else {
      L[i+1] = 1;
      R[i+1] = T[i+1];
    }
  }
  LL ans = 1;
  rep(i, N) {
    int j=i+1;
    if (A[j] > A[j+1]) {
      L[j] = max(L[j], A[j]);
      R[j] = min(R[j], A[j]);
    } else {
      L[j] = max(L[j], 1);
      R[j] = min(R[j], A[j]);
    }
    
    if (L[j] > R[j]) {
      puts("0");
      return 0;
    }
    (ans *= LL(R[j]-L[j]+1)) %= MOD;
  }
  printf("%lld\n", ans);
}
      
    
    
