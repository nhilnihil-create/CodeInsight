#include <bits/stdc++.h> 
using namespace std;

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(x) (x).begin(),(x).end()
#define foreach(u,v) for(auto (u) : (v))
#define pb push_back
#define mp make_pair
#define mt make_tuple

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;

const int inf = 1e9;
const ll linf = 1LL<<60;
const ll mod = 1e9 + 7;
const double eps = 1e-9;

/*
*/

int main()
{
  int n, k;
  cin >> n >> k;

  vi a(n), b(n);
  rep(i, n){
    cin >> a[i] >> b[i];
  }

  ll ans = 0;
  int mask = 0;
  for(int i = 30; i >= 0; i--){
    if(1<<i & k){
      ll tmp = 0;
      rep(j, n){
        if(!(a[j]&(mask|1<<i))) tmp += b[j];
      }
//      cout << i << " , " << tmp << endl;
      ans = max(ans, tmp);
    }else{
      mask |= 1<<i;
    }
  }

  ll tmp = 0;
  rep(i, n){
    if(!(a[i]&mask)) tmp += b[i];
  }
  ans = max(ans, tmp);

  cout << ans << endl;

  return 0;
}
