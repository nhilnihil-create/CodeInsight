#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ld EPS = 1e-8;

int main(){
  int N;
  cin >> N;
  vector<ll> a(N);
  REP(i,N) cin >> a[i];

  vector<ll> cum(N + 1, 0);
  REP(i,N) cum[i + 1] = cum[i] + a[i];

  ll ret = 1e18;
  REP(i,N-1) {
    ll s = cum[i + 1];
    ll a = cum[N] - s;
    ret = min(ret, abs(s - a));
  }

  cout << ret << endl;
  return 0;
}

