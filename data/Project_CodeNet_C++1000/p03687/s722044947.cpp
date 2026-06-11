#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64
#define rep(i, n) for(int i=0; i<n; i++)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define SORT(x) sort(x.begin(), x.end())
#define GSORT(x) sort(x.begin(), x.end(), greater<int>())
#define mk make_pair
#define fi first
#define se second
#define pb push_back
#define ALL(x) x.begin(), x.end()
#define V(T) vector<T>
typedef pair<int, int> P;
typedef pair<P, P> PP;
typedef vector<int> vi;
typedef vector<vi> vvi;
int max(int a, int b) {if(b>a) return b; else return a;}
int min(int a, int b) {if(b<a) return b; else return a;}
const int INF = 1e18;

signed main() {
    string s;
    cin >> s;
    int l = s.size();

    vvi pos(26);
    rep(i, l) {
        pos[s[i]-'a'].pb(i);
    }

    int res = INF;
    rep(i, 26) {
        if(!pos[i].size()) continue;
        int t = 0, now = 0;
        rep(j, pos[i].size()) {
            if(!j) t = max(t, pos[i][j]);
            else t = max(t, pos[i][j]-now-1);
            now = pos[i][j];
        }
        t = max(t, l-1-pos[i].back());
        res = min(res, t);
    }

    cout << res << endl;

    return 0;
}