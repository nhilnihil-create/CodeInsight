#include<bits/stdc++.h>
#include<math.h>
using namespace std;
#define rep(i,n) for (int i=0;i<n;i++)
#define pi 3.1415926535897932384

int main(){
  int N, M, K; cin >> N >> M >> K;

  bool possible = false;
  rep(i,N+1){
    rep(j,M+1){
      if (K == (N-i)*j + i*(M-j)) {
        possible = true;
        break;
      }
    }
  }
  cout << (possible? "Yes" : "No") << endl;
  return 0;
}

 