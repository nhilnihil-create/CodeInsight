#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
#define REP(i, limit) for(int i=0; i< limit; ++i)
#define LINT long long

int main(){
  int N;
  cin >> N;
  LINT a[N];
  LINT sum1=0, sum2 = 0;
  LINT ans;
  REP(i, N){
    cin >> a[i];
    if(i) sum2 += a[i];
    else sum1 += a[i];
  }
  ans = abs(sum1 - sum2);
  if(N == 2){
    cout << ans << endl;
    return 0;
  }
  REP(i, N-2){
  sum1 += a[i+1];
  sum2 -= a[i+1];
    ans = min(ans, abs(sum1-sum2));
  }
  cout << ans << endl;
  return 0;
}
