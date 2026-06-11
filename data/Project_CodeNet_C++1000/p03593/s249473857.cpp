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
const int MOD = 1e9 + 7;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll h,w;
  cin >> h >> w;
  vll v(26, 0);
  REP(i, h){
    string s;
    cin >> s;
    REP(j, s.size())
      v[s[j]-'a']++;
  }

  ll p1, p2, p4;
  p1=p2=p4=0;
  REP(i, 26){
    p4 += v[i]/4;
    p2 += v[i]%4/2;
    p1 += v[i]%2;
  }

  ll acp2 = 0;
  if(h%2==1)
    acp2 += w/2;
  if(w%2==1)
    acp2 += h/2;

  string ans="Yes";
  if(acp2<p2 || (acp2-p2)%2!=0)
    ans = "No";

  if((h%2==1 && w%2==1 && p1!=1) || ((h%2==0 || w%2==0) && p1!=0))
    ans = "No";

  cout << ans << endl;

}
