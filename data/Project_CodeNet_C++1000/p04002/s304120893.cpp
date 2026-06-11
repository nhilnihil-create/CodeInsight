#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define FOR(i,a,b)  for(ll (i)=a;(i)<(b);++(i))
#define RFOR(i,a,b) for(ll (i)=a;(i)>=(b);--(i))
#define REP(i,n)    FOR(i,0,n)
#define RREP(i,n)   RFOR(i,n,0)
#define SZ(v)       (ll)(v).size()
#define ALL(v)      (v).begin(), (v).end()
#define UNIQ(v)     sort(ALL(v)); (v).erase(unique(ALL(v)), (v).end())
#define IN(x,l,r)   ((l)<=(x) && (x)<=(r))
#define BIT(n)      (1LL<<(n))
#define PQ(T)       priority_queue<T, vector<T>, greater<T>>
#define SHOW(x)     cout << #x << " = " << x << endl

template<typename T>string join(const vector<T>& v, string d=" ")
{stringstream s;REP(i,SZ(v))s<<d<<v[i];return s.str().substr(d.length());}

template<typename T> ostream& operator<<(ostream& s, const vector<T>& v)
{if(SZ(v))s<<join(v,", ");return s;}

const ll inf = 1e15;
const ll mod = 1e9+7;
const double eps = 1e-10;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int main() {
    ll H, W, N; cin >> H >> W >> N;
    
    set<pair<ll, ll>> S1, S2;
    REP(i, N) {
        ll x, y; cin >> x >> y;
        S1.insert(make_pair(x, y));
        REP(j, 3) REP(k, 3) S2.insert(make_pair(x-j, y-k));
    }
    
    vector<ll> ans(10);
    ans[0] = (H-2)*(W-2);
    for (auto p: S2) {
        ll x = p.first;
        ll y = p.second;
        
        if (not IN(x, 1, H-2)) continue;
        if (not IN(y, 1, W-2)) continue;
        
        ll sum = 0;
        REP(j, 3) REP(k, 3) sum += S1.count(make_pair(x+j, y+k));
        
        ans[sum]++;
        ans[0]--;
    }
    
    for (auto x: ans) {
        cout << x << endl;
    }
    
    return 0;
}
