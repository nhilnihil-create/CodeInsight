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
const long long INF = 1e18;
const double PI = 2 * asin(1);
typedef long long ll;


int main(){
  int N, Ma, Mb; cin >> N >> Ma >> Mb;

  vector <int> A(N), B(N), C(N);
  for (int i = 0; i < N; i++){
    cin >> A[i] >> B[i] >> C[i];
  }

  int DP[N + 1][401][401];
  for (int i = 0; i < N + 1; i++){
    for (int j = 0; j < 401; j++){
      for (int k = 0; k < 401; k++){
        DP[i][j][k] = nmax;
      }
    }
  }
  DP[0][0][0] = 0;

  for (int i = 1; i < N + 1; i++){
    for (int j = 0; j < 401; j++){
      for (int k = 0; k < 401; k++){
        DP[i][j][k] = DP[i - 1][j][k];
        if (j - A[i - 1] >= 0 && k - B[i - 1] >= 0){
          DP[i][j][k] = min(DP[i][j][k], DP[i - 1][j-A[i-1]][k-B[i-1]] + C[i-1]);
        }
      }
    }
  }

  int ans = nmax;
  for (int i = 1; i * Ma <= 400 && i * Mb <= 400; i++){
    ans = min(ans, DP[N][i * Ma][i * Mb]);
  }

  if (ans == nmax) ans = -1;
  cout << ans << endl;
    
  return 0;
}
