#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;


int main() {
  int N, K; cin >> N >> K;
  ll a[N]; rep(i,N) cin >> a[i];
  ll sp[N+1]= {}, sm[N+1]={}; 
  rep(i,N) {
    if (i==0) {
      if (a[i]>=0) sp[i+1] = a[i];
      else sm[i+1] = a[i];
    }
    else {
      sp[i+1] = sp[i]; sm[i+1] = sm[i];
      if (a[i]>=0) sp[i+1] += a[i];
      else sm[i+1] += a[i];
    }
  }
  ll rp = LLINF, rm = -1*LLINF;
  rep(i,N-K+1) {
    rp = min(rp, sp[i+K]-sp[i]);
    rm = max(rm, sm[i+K]-sm[i]);
  }
  ll result = 0; rep(i,N) if (a[i]>=0) result += a[i];
  result -= min(rp, -1*rm);
  cout << result << endl;
  return 0;
}