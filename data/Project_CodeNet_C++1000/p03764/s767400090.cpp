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
  #define int long long 

  int n, m;
  cin >> n >> m;

  vl x(n), y(m);
  rep(i, n) cin >> x[i];
  rep(i, m) cin >> y[i];

  ll sx = 0;
  rep(i, n-1){
    sx += (i+1)*(n-1-i)%mod*(x[i+1]-x[i])%mod;
    sx %= mod;
  }

  ll sy = 0;
  rep(i, m-1){
    sy += (i+1)*(m-1-i)%mod*(y[i+1]-y[i])%mod;
    sy %= mod;
  }

  cout << sx*sy%mod << endl;

  return 0;
}
