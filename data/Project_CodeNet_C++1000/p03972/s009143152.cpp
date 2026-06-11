#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef pair<ll, pair<ll, ll> > P3;

const ll MOD = ll(1e9 + 7);
const ll LLINF = LLONG_MAX;
const int IINF = INT_MAX;
const int MAX_N = int(3e5) + 5;
const double EPS = 1e-8;
const int di[] = {0, 1, 0, -1}, dj[] = {1, 0, -1, 0};
string dir = "RDLU";
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) (v).begin(), (v).end()

int main() {
    ll w,h;
    vector<P> edges;
    cin >> w >> h;
    REP(i,w){
        ll p;
        cin >> p;
        edges.push_back({p,0});
    }
    REP(i,h){
        ll q;
        cin >> q;
        edges.push_back({q,1});
    }
    sort(ALL(edges));
    ll ans = 0;
    for(auto e : edges){
        ans += e.first*(e.second?w+1:h+1);
        if(e.second)h--;
        else w--; 
    }
    cout << ans << endl;
    return 0;
}