#include <bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
const long long LINF = 1e18;
#define dump(x)  cout << 'x' << ' = ' << (x) << ` `;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOREACH(x,a) for(auto& (x) : (a) )
typedef long long ll;
using namespace std;

typedef pair<ll, ll> P;
map<P, int> mp;
int dy[] = {0, 0, 1, 0, -1, 1, -1, 1, -1};
int dx[] = {0, 1, 0, -1, 0, 1, 1, -1, -1};
ll h, w, n;

bool check(ll A, ll B) {
    REP(k, 9) {
        ll AA = A + dy[k];
        ll BB = B + dx[k];
        if (min(AA, BB) <= 0 || AA > h || BB > w) return true;
    }
    return false;
}

int main(int argc, char const *argv[]) {
    cin >> h >> w >> n;
    REP(i,n) {
        ll a, b;
        cin >> a >> b;
        REP(j,9) {
            ll A = a+dy[j]; ll B = b+dx[j];
            P p = make_pair(A, B);
            if (check(A, B)) continue;
            mp[p]++;
        }
    }
    vector<ll> cnt(10, 0);
    for (auto &x: mp) cnt[x.second]++;
    ll sum = accumulate(cnt.begin(), cnt.end(), 0);
    cnt[0] = (h-2)*(w-2)-sum;
    REP(i,10) cout << cnt[i] << endl;
    return 0;
}