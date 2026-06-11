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

int main(){
  int N,K;
  cin >> N >> K;

  ll a[N];
  ll sum[N+1] = {};
  ll sump[N+1] = {};
  for(int i=0;i<N;i++){
    cin >> a[i];
    sum[i+1] = sum[i] + a[i];
    if(a[i] > 0LL) sump[i+1] = sump[i] + a[i];
    else sump[i+1] = sump[i];
  }

  /*for(int i=0;i<=N;i++){
    cout << sum[i] << " ";
  }
  cout << endl;
  for(int i=0;i<=N;i++){
    cout << sump[i] << " ";
  }
  cout << endl;*/

  ll ans = 0LL;
  for(int i=0; i<=N-K; i++){
    ll tmp;
    ll sm = sum[i+K] - sum[i];
    tmp = max(0LL, sm);
    tmp += sump[i] - sump[0];
    tmp += sump[N] - sump[i+K];

    ans = max(ans, tmp);
  }

  cout << ans << endl;
  return 0;
}