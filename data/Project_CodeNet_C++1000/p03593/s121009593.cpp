#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define FORMAP(x, mp) for(auto x=mp.begin();x!=mp.end();x++)
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define SUM(x) accumulate(ALL(x), 0)
#define print(x) cout << x;
#define println(x) cout << x << endl;
#define printd(x, f) cout << fixed << setprecision(f) << x << endl;

#define PB push_back
#define MP make_pair
#define F first
#define S second

#define INF 1000000000000
#define MOD 10000007
#define MAXR 100000
#define PI acos(-1.0)

#define NO "No"
#define YES "Yes"

int h, w;
vector<string> s(101);
map<char, int> mp;

string solve()
{
  REP(i, h) REP(j, w) mp[s[i][j]]++;

  if (h % 2 == 0 && w % 2 == 0) {
    FORMAP(x, mp) if (x->S % 4) return NO;
    return YES;
  }

  if (h % 2 && w % 2) {
    map<int, int> c;
    FORMAP(x, mp) c[x->S % 4]++;
    if (c[3]) return NO;
    if (c[1] != 1) return NO;
    if (c[2] > (h - 1) / 2 + (w - 1) / 2) return NO;
    return YES;
  }

  if (w % 2) swap(h, w);
  map<int, int> c;
  FORMAP(x, mp) c[x->S % 4]++;
  if (c[1] || c[3]) return NO;
  if (c[2] > w / 2) return NO;
  return YES;
}

int main()
{
  cin >> h >> w;
  REP(i, h) cin >> s[i];
  println(solve());
  return 0;
}
