#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
typedef long long ll;
const ll INF = 1e15;

int main(){
  int n;
  cin >> n;
  ll a[3*n];
  rep(i, 3*n) cin >> a[i];
  ll suml[n+1], sumr[n+1];
  suml[0] = 0, sumr[0] = 0;
  priority_queue<ll, vector<ll>, greater<ll>> sl;
  priority_queue<ll> sr;
  rep(i, n){
    sl.push(a[i]); suml[0] += a[i];
    sr.push(a[3*n-1-i]); sumr[0] += a[3*n-i-1];
  }
  rep(i, n){
    sl.push(a[n+i]);
    suml[i+1] = suml[i] + a[n+i] - sl.top();
    sl.pop();
    sr.push(a[2*n-1-i]);
    sumr[i+1] = sumr[i] + a[2*n-1-i] - sr.top();
    sr.pop();
  }
  ll ans = -INF;
  rep(i, n+1) ans = max(ans, suml[i]-sumr[n-i]);
  cout << ans << endl;
  return 0;
}
