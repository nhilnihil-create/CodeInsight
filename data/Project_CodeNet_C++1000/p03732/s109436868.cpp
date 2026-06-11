#include <bits/stdc++.h>
using namespace std;

// types
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef vector<ll> vll;

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
const int MOD = 1e9 + 7;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n,W;
  cin >> n >> W;

  vll w(n), v(n);
  REP(i, n)
    cin >> w[i] >> v[i];

  vector<vll> s(4, vll(1, 0));
  REP(i, n)
    s[w[i]-w[0]].push_back(v[i]);

  for(auto &p : s){
    sort(p.rbegin(), p.rend()-1);
    REP1(i, p.size())
      p[i] += p[i-1];
  }

  ll ans = 0;
  for(ll i=0; i<=s[0].size(); i++){
    for(ll j=0; j<=s[1].size(); j++){
      for(ll k=0; k<=s[2].size(); k++){
        for(ll t=0; t<=s[3].size(); t++){
          if(w[0]*(i+j+k+t)+j+2*k+3*t > W)
            continue;

          ans = max(ans, s[0][i]+s[1][j]+s[2][k]+s[3][t]);

        }
      }
    }

  }

  cout << ans << endl;

}
