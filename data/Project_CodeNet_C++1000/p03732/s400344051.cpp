#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {

  long long N, W;
  cin >> N >> W;

  long long wList[N];
  long long vList[N];

  for ( int i=0; i<N; i++ ) {
    cin >> wList[i] >> vList[i];
  }

  long long wBase = wList[0];
  long long W_ = 305LL;
  for ( int i=0; i<N; i++ ) {
    wList[i] -= wBase;
  }

  long long dp[N+1][N+1][W_+1];
  for ( int n=0; n<N; n++ ) {
    for ( int k=0; k<N; k++ ) {
      for ( int w=0; w<=W_; w++ ) {
         dp[n][k][w]=0;
      }
    }
  }
  dp[0][0][0] = 0;
  for ( int n=0; n<N; n++ ) {
    for ( int k=0; k<N; k++ ) {
      for ( int w=0; w<=W_; w++ ) {

        if ( w-wList[n] >= 0 ) {
          dp[n+1][k+1][w] = max( dp[n][k][w-wList[n]] + vList[n], dp[n][k+1][w] );
        } else {
          dp[n+1][k+1][w] = dp[n][k+1][w];
        }

      }
    }
  }

  long long max_v = 0;
  for ( int k=0; k<=N; k++ ) {
    long long amari = W - k*wBase;
    if ( amari >= 0 ) {
      max_v = max( max_v, dp[N][k][min(amari, 300LL)] );
    }
  }
  cout << max_v << endl;

  return 0;
}