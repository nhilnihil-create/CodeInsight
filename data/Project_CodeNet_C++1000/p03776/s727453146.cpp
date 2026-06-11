#include <bits/stdc++.h>
using namespace std;

// types
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef vector<ll> vll;
typedef vector<pll> vpl;

// macros
#define ALL(a) a.begin(),a.end()
#define SZ(a) ((int)a.size())
#define FI first
#define SE second
#define REP(i,n) for(int i=0;i<((int)n);i++)
#define REP1(i,n) for(int i=1;i<((int)n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define PB push_back
#define EB emplace_back
#define MP(a,b) make_pair(a,b)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL

// constants
const int inf = 1e9;
const ll linf = 1LL << 50;
const double eps = 1e-10;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

const ll MAX = 50;

vector<map<ll,ll>> fac(MAX+1);

void COMinit() {
  for (ll i=2; i<=MAX; i++){
    ll x=i;
    for(ll j=2; j<=i; j++){
      ll cnt=0;
      while(x%j==0){
        cnt++;
        x/=j;
      }

      fac[i][j] = fac[i-1][j]+cnt;
    }

    fac[i][x] = fac[i-1][x]+1;
  }
}

ll COM(ll n, ll k){
  ll res=1;
  for(ll i=MAX; i>=2; i--){
    ll cnt=fac[n][i]-fac[n-k][i]-fac[k][i];
    res = res*1.0*pow(i,cnt);
  }

  return res;
}



int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n,a,b;
  cin >> n >> a >> b;
  vll v(n);
  REP(i, n)
    cin >> v[i];

  sort(v.begin(), v.end(), greater<ll>());

  ld sum = 0;
  REP(i, a)
    sum += v[i];
  ld ave = sum/1.0/a;

  REP(i, n)
    v[i] *= -1;
  COMinit();
  ll ans = 0;

  if(v[0]==v[a-1]){
    auto it = upper_bound(v.begin(), v.end(), v[a-1]);
    ll num = it-v.begin();

    for(ll i = a; i<=b; i++){
      if(num<i)
        break;

      ans += COM(num,i);
    }
  }
  else{
    auto itb = lower_bound(v.begin(), v.end(), v[a-1]);
    auto ita = upper_bound(v.begin(), v.end(), v[a-1]);
    ll num = ita-v.begin();

    ans += COM(ita-itb,a-(itb-v.begin()));
  }

  cout << Decimal;
  cout << ave << endl;
  cout << ans << endl;
}
