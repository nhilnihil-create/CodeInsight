#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define REP(i,a,n) for(int i = a;i < (n);i++)
#define RREP(i,a) for(int i = a;i >= 0;i--)
#define rep(i,n) for(int i = 0;i < (n);i++)
#define rrep(i,n) for(int i = n - 1;i >= 0;i--)
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define range(x,min,max) ((min) <= (x) && (x) <= (max))
#define xyrange(x, minX, maxX, y, minY, maxY) (range(x, minX, maxX) && range(y, minY, maxY))

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef pair<int,int> PII;
typedef vector<PII> VPII;

const int DX[]={1,0,-1,0},DY[]={0,-1,0,1};
const int INF = 0x3f3f3f3f;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    VI as, bs, cs, ds;
    rep (i, N) {
        int a, b;
        cin >> a >> b;
        as.pb(a);
        bs.pb(b);
    }
    rep (i, M) {
        int c, d;
        cin >> c >> d;
        cs.pb(c);
        ds.pb(d);
    }
    VI ans;
    rep (i, N) {
        int min_dist = INF;
        int point = -1;
        rep (j, M) {
            int x = max(as[i], cs[j]) - min(as[i], cs[j]);
            int y = max(bs[i], ds[j]) - min(bs[i], ds[j]);
            int dist = x + y;
            if (min_dist > dist) {
                min_dist = dist;
                point = j;
            }
        }
        ans.pb(point + 1);
    }
    for (auto &a : ans) {
        cout << a << endl;
    }
    return 0;
}