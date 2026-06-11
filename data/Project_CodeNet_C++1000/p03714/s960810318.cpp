#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(a); (i)<(b); (i)++)
#define rFor(i, a, b) for(int (i)=(a)-1; (i)>=(b); (i)--)
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
using namespace std;

int main(){
  int n; cin >> n;
  long a[n*3], asum[n*3+1];
  asum[0] = 0;
  rep(i, n*3) cin >> a[i], asum[i+1] = asum[i] + a[i];
  long sumin[n+1], sumax[n+1]; sumin[0] = sumax[n] = 0;
  priority_queue<long, vector<long>, greater<long>> qmin;
  priority_queue<long> qmax;
  rep(i, n) qmin.push(a[i]), qmax.push(a[3*n-1-i]);
  rep(i, n){
    qmin.push(a[i+n]); sumin[i+1] = sumin[i] + qmin.top(); qmin.pop();
    qmax.push(a[2*n-1-i]); sumax[n-1-i] = sumax[n-i] + qmax.top(); qmax.pop();
  }
  long ans = -LONG_MAX;
  rep(i, n+1) ans = max(ans, asum[n+i]-sumin[i]-(asum[n*3]-asum[n+i]-sumax[i]));
  cout << ans << endl;
}