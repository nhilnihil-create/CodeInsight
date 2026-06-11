#pragma GCC optimize ("O3")
#pragma GCC target (sse, sse1, sse2, tune=native, popcnt)

#include <bits/stdc++.h>
/*
const int MAX_MEM = 25e7;
int mpos = 0;
char mem[MAX_MEM];
inline void* operator new(size_t n) {
    char *res = mem + mpos;
    mpos += n;
    assert(mpos <= MAX_MEM);
    return (void *) res;
}
inline void operator delete(void *) {}
*/
using namespace std;

#define loop(i, n) for(int i = 0; i < n; ++i)
#define FOR(i, a, n) for(int i = a; i < n; ++i)
#define vec vector
#define paii pair<int, int>
#define fr first
#define sc second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define SZ(x) (int)x.size()
#define Unique(x) x.erase(unique(all(x)), x.end())

#define int long long

const int inf = 1e17 + 47, MAXN = 2047, N = 20, mod = 1e9 + 7;

mt19937 rnd(time(0));

int n, k;
int d[MAXN], cnt[MAXN];
vec<int> graf[MAXN];

paii bfs(int st, int pr) {
    vec<int> pt;
    pt.pb(pr);
    d[pr] = -1;
    d[st] = 1;
    queue<int> q;
    q.push(st);
    while(!q.empty()) {
        int p1 = q.front();
        q.pop();

        pt.pb(p1);
        cnt[d[p1]]++;

        for(int p2 : graf[p1]) {
            if(d[p2] > d[p1] + 1) {
                d[p2] = d[p1] + 1;
                q.push(p2);
            }
        }
    }
    /*cout << st + 1 << ": ";
    loop(i, 5) cout << cnt[i] << " ";
    cout << endl*/;

    int kek = cnt[0];
    FOR(i, 1, k / 2) {
        if(cnt[i] == 0) break;
        cnt[i] += cnt[i - 1];
        kek = cnt[i];
    }
    paii p = {kek, kek + cnt[k / 2]};
    FOR(i, 1, n) {
        if(cnt[i] == 0) break;
        cnt[i] = 0;
    }
    for(int c : pt) d[c] = inf;
    return p;
}

void solve() {
    loop(i, MAXN) d[i] = inf;
    loop(i, MAXN) cnt[i] = 0;
    cin >> n >> k;
    if(k == 1) {
        if(n == 1) cout << 0 << endl;
        else cout << n - 2 << endl;
        return ;
    }
    k++;
    loop(i, n - 1) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        graf[a].pb(b);
        graf[b].pb(a);
    }
    int ans = 0;
    loop(p1, n) {
        //cout << p1 + 1 << ": " << endl;
        vec<paii> t;
        for(int p2 : graf[p1]) {
            t.pb(bfs(p2, p1));
            //cout << t.back().fr << " " << t.back().sc << endl;
        }
        if(k % 2 == 1) {
            int sum = 1;
            for(paii p : t) sum += p.sc;
            ans = max(ans, sum);
        } else {
            int sum = 1;
            for(paii p : t) sum += p.fr;
            for(paii p : t) {
                int k = sum - p.fr + p.sc;
                ans = max(ans, k);
            }
        }
        //cout << endl;
    }
    cout << n - ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie();

    #ifdef COFFEE_MACHINE
        freopen("input.cpp", "r", stdin);
        freopen("output.cpp", "w", stdout);
    #endif // COFFEE_MACHINE

    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
}
