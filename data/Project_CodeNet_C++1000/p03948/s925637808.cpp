#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int inf = 1e9;
const ll linf = 1e18;
const ll mod = 1e9 + 7;

int main()
{
  int n, t;
  cin >> n >> t;

  vi a(n);
  rep(i, n) cin >> a[i];

  int ma = 0, mi = a[0];
  repi(i, 1, n){
    ma = max(ma, a[i] - mi);
    mi = min(mi, a[i]);
  }

  int ans = 0;
  mi = a[0];
  repi(i, 1, n){
    if(a[i] - mi == ma) ans++;
    mi = min(mi, a[i]);
  }

  cout << ans << endl;

  return 0;
}
