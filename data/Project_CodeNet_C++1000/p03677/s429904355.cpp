#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> p_ll;

template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }
#define repr(i,from,to) for (int i=(int)from; i<(int)to; i++)
#define all(vec) vec.begin(), vec.end()
#define rep(i,N) repr(i,0,N)
#define per(i,N) for (int i=(int)N-1; i>=0; i--)

const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;

int main() {
  int n, m; cin >> n >> m;
  int a[n]; rep(i,n) { cin >> a[i]; a[i]--; }

  ll d[m*2+1] = {};
  repr(i,1,n) {
    if (a[i]>a[i-1]) { 
      d[a[i-1]+2] += 1; 
      d[a[i]+1] -= a[i]-a[i-1]; 
      d[a[i]+2] += a[i]-a[i-1]-1;
    }
    else {
      d[a[i-1]+2] += 1;
      d[a[i]+m+1] -= a[i]+m-a[i-1];
      d[a[i]+m+2] += a[i]+m-a[i-1]-1;
    }
  }
  ll v[m*2+1] = {};
  repr(i,1,m*2+1) d[i] += d[i-1];
  repr(i,1,m*2+1) v[i] = v[i-1] + d[i];
  rep(i,m) v[i] += v[i+m];
  // debug(d,d+m*2+1); debug(v,v+m);
  ll ma = 0; rep(i,m) ma = max(ma,v[i]);

  ll result = 0;
  repr(i,1,n) result += (a[i]+m-a[i-1])%m;
  result -= ma;
  cout << result << endl;
  return 0;
}