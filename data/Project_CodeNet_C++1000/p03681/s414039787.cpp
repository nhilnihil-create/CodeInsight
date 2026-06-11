#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t mod=pow(10,9)+7;
  int N, M;
  cin >> N >> M;
  int64_t ans=1;
  if (N==M) {ans=2;}
  if (abs(N-M)>1) {ans=0;}
  else {
    for (int i=1; i<=N; i++) {
      ans*=i;
      ans=ans-ans/mod*mod;
    }
    for (int i=1; i<=M; i++) {
      ans*=i;
      ans=ans-ans/mod*mod;
    }
  }
  cout << ans << endl;
}