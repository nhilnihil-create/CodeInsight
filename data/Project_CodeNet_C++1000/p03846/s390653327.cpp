#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9+7;

int main() {
  int N;
  cin >> N;
  int A[N];
  for (int i=0 ; i < N; i++){
    cin >> A[i];
  }

  sort( A , A + N);

  if(N%2){
    for (int i = 0; i < N; i++){
      if (A[i] != (i+1)/2 * 2 ){
        cout << 0 << endl;
        return 0;
      }
    }
  }
  else{
    for (int i = 0; i < N;i++){
      if (A[i] != i/2 * 2 + 1) {
        cout << 0 << endl;
        return 0;
    }
  }
}

ll ans = 1;
for (int i=0; i<N/2; i++) {
  ans *= 2;
  ans %= MOD;
}
cout << ans << endl;
return 0;


}
