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
const long long MOD = 1000000007;
long long x[100000];

long long fact(int n){
  long long ans = 1;
  for(int i = 1; i <= n; i++){
    ans = (ans * i) % MOD;
  }
  return ans;
}

int main(){
  int N;
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> x[i];
  }

  long long ans = 1;
  int removed = 0;
  for(int i = 1; i < N; i++){
    if(x[i] % 2 == 0){
        if(x[i] / 2 < (i + 1 - removed)){
            ans = (ans * (i - removed + 1)) % MOD;
            removed ++;
        }
    } else {
        if((x[i] + 1) / 2 < (i + 1 - removed)){
            ans = (ans * (i - removed + 1)) % MOD;
            removed ++;
        }
    }
  }
  ans = (ans * fact(N - removed)) % MOD;
  cout << ans << endl;
  return 0;
}
