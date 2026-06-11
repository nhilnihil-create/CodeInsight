#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;



int main() {

  int N, K; cin >> N >> K;
  int x[N];
  rep(i,N) cin >> x[i];
  int ans = 0;
  rep(i,N){
    int A = x[i] * 2;
    int B = abs(x[i] - K) * 2;
    ans+= min(A,B);
  }
  cout << ans << endl;




  return 0;
}






