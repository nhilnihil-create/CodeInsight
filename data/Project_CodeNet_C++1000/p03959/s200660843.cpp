#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

const long long MOD = 1000000007LL;

int main(){
  int N;
  cin >> N;
  ll T[N],A[N];
  for(int i=0;i<N;i++) cin >> T[i];
  for(int i=0;i<N;i++) cin >> A[i];

  ll mn[N], mx[N];
  for(int i=0;i<N;i++){
    if(i == 0){
      mn[i] = T[i];
      mx[i] = T[i];
    }
    else if(T[i] > T[i-1]){
      mn[i] = T[i];
      mx[i] = T[i];
    }
    else{
      mn[i] = 1LL;
      mx[i] = T[i];
    }
  }

  for(int i=N-1; i>=0; i--){
    if(i == N - 1){
      mn[i] = max(mn[i], A[i]);
      mx[i] = min(mx[i], A[i]);
    }
    else if(A[i] > A[i+1]){
      mn[i] = max(mn[i], A[i]);
      mx[i] = min(mx[i], A[i]);
    }
    else{
      mn[i] = max(mn[i], 1LL);
      mx[i] = min(mx[i], A[i]);
    }
  }

  ll ans = 1LL;
  for(int i=0;i<N;i++){
    if(mn[i] > mx[i]){
      cout << 0 << endl;
      return 0;
    }
    else{
      ans *= (mx[i] - mn[i] + 1);
      ans %= MOD;
    }
  }

  cout << ans << endl;
  return 0;
}
