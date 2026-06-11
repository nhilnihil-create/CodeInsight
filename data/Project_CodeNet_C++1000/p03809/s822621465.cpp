//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define db long double
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define mp make_pair
#define all(x) (x).begin(), (x).end()

void dout() { cerr << '\n'; }

template <typename Head, typename... Tail>
void dout(Head H, Tail... T) {
    cerr << " " << H;
    dout(T...);
}

#ifdef LOCAL
    #define dbg(...) cerr << #__VA_ARGS__, dout(__VA_ARGS__)
#else
    #define dbg(...) ;
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef pair <int, int> pii;

const int N = 1e5 + 123;
int n, a[N];
ll s[N];
vector <int> adj[N];
vector <ll> c[N];

void dfs(int v, int p) {
    for (int to : adj[v]) {
        if (to == p) {
            continue;
        }
        dfs(to, v);
        ll w = 2 * a[to] - s[to];
        if (adj[to].size() == 1) {
            w = a[to] - s[to];
        }
        c[v].pb(w);
        c[to].pb(w);
        if (w < 0) {
            cout << "NO";
            exit(0);
        }
        s[v] += w;
        s[to] += w;
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (n == 2) {
        if (a[1] == a[2]) {
            cout << "YES";
        }   else {
            cout << "NO";
        }
        return 0;
    }
    for (int i = 1; i <= n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1, 1);
    if (adj[1].size() == 1 && s[1] != a[1]) {
        cout << "NO";
        return 0;
    }
    if (adj[1].size() > 1 && s[1] != 2 * a[1]) {
        cout << "NO";
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() == 1) {
            continue;
        }
        for (int j : c[i]) {
            if (j > s[i] / 2) {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
}
