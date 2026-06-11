#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <queue>

using namespace std;

const int nmax = 1e9 + 7;
typedef long long ll;

int main(){
  int N; cin >> N;
  
  vector <ll> T(N), A(N);
  for (int i = 0; i < N; i++) cin >> T[i];
  for (int i = 0; i < N; i++) cin >> A[i];

  vector <ll> H1(N), H2(N);

  H1[0] = T[0];
  for (int i = 1; i < N; i++){
    if (T[i - 1] < T[i]){
      H1[i] = T[i];
    }
  }
  
  H2[N - 1] = A[N - 1];
  for (int i = N - 2; i >= 0; i--){
    if (A[i] > A[i + 1]){
      H2[i] = A[i];
    }
  }

  ll ans = 1;
  for (int i = 0; i < N; i++){
    if (H1[i] == 0 && H2[i] == 0){
      ans *= min(T[i], A[i]);
    }else if(H1[i] != 0 && H2[i] != 0 && H1[i] != H2[i]){
      ans = 0;
    }else if(H1[i] != 0 && H2[i] == 0 && H1[i] > A[i]){
      ans = 0;
    }else if(H1[i] == 0 && H2[i] != 0 && T[i] < H2[i]){
      ans = 0;
    }
    ans %= nmax;
  }
  cout << ans << endl;


  return 0;
}
