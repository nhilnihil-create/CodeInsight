#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>
#include <set>
#include <cmath>
#include <numeric>
#include <iomanip>

using namespace std;
long long T[100000];
long long A[100000];
bool decided_T[100000];
bool decided_A[100000];
const long long MOD = 1000000007;
int main(){
  int N;
  cin >> N;
  for(int i = 0; i < N; i++){
      cin >> T[i];
  }
  for(int i = 0; i < N; i++){
      cin >> A[i];
  }
  
  decided_T[0] = true;
  decided_A[N - 1] = true;
  for(int i = 1; i < N; i++){
      if(T[i - 1] != T[i]){
          decided_T[i] = true;
      }
  }
  for(int i = N - 2; i >= 0; i--){
      if(A[i] != A[i + 1]){
          decided_A[i] = true;
      }
  }
  
  
  long long ans = 1;
  for(int i = 0; i < N; i++){
      if(decided_T[i] || decided_A[i]){
          if((decided_T[i] && T[i] > A[i]) || (decided_A[i] && T[i] < A[i]) || (decided_T[i] && decided_A[i] && A[i] != T[i])){
              cout << 0 << endl;
              return 0;
          }
      } else {
          ans = (ans * min(A[i], T[i])) % MOD;
      }
  }
  cout << ans << endl;
  
  return 0;
}
