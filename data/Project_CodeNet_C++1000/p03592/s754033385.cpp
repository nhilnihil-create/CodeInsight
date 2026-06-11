#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
  int N, M, K; cin >> N >> M >> K;
  bool ok = false;
  for(int i = 0; i <= N; i++){
    for(int j = 0; j <= M; j++){
      int x = i * M + j * N - 2 * i * j;
      if(x == K) ok = true;
    }
  }
  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
}
