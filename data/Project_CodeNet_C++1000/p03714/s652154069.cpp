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
typedef unsigned int uint;
using namespace std;

int main(){
  int N;
  cin >> N;
  ll a[N],b[N],c[N];
  for(int i=0;i<N;i++) cin >> a[i];
  for(int i=0;i<N;i++) cin >> b[i];
  for(int i=0;i<N;i++) cin >> c[i];

  priority_queue<ll, vector<ll>, greater<ll> > pql;
  priority_queue<ll> pqr;
  ll suml = 0LL;
  ll sumr = 0LL;
  for(int i=0;i<N;i++){
    pql.push(a[i]);
    suml += a[i];
    pqr.push(c[i]);
    sumr += c[i];
  }

  //iまで使えるときの左の総和の最大値
  ll sml[N+1];
  sml[0] = suml;
  for(int i=1;i<=N;i++){
    suml += b[i-1];
    pql.push(b[i-1]);
    suml -= pql.top();
    pql.pop();
    sml[i] = suml;
  }

  //左がiまで使うときの右の総和の最小値
  ll smr[N+1];
  smr[N] = sumr;
  for(int i=N-1;i>=0;i--){
    sumr += b[i];
    pqr.push(b[i]);
    sumr -= pqr.top();
    pqr.pop();
    smr[i] = sumr;
  }

  /*for(int i=0;i<=N;i++){
    cout << sml[i] << " " << smr[i] << endl;
  }*/

  ll ans = sml[0] - smr[0];
  for(int i=1;i<=N;i++){
    ans = max(ans, sml[i] - smr[i]);
  }

  cout << ans << endl;
  return 0;
}
