#include <bits/stdc++.h>
 
#define pii pair<int, int>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define ll long long 
#define ld long double
#define sz(v) int(v.size())
#define all(v) v.begin(), v.end()
 
#define y1 what

using namespace std;
 
const int N = (int) 4e5 + 10;
const int M = (int) 1e6 + 10;
const ll LINF = (ll) 2e18;
const int INF = (int) 1e9 + 7;
const double EPS = (double) 1e-9;
const double PI =  3.14159265359;

int n;
vector<int> v[N];
int sz[N];

int dfs(int x, int p = -1) {
    int ans = 0;
    for (auto it : v[x]) {
        if (it != p) {
            ans ^= dfs(it, x) + 1;
        }
    }
    return ans;
}

int main() {
    #define fn "euler"
    #ifdef witch                                                            
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        //freopen(fn".in", "r", stdin);
        //freopen(fn".out", "w", stdout);
    #endif      
    cin >> n;
    for (int i = 1, x, y; i < n; i++) {
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    if (dfs(1)) cout << "Alice";
    else cout << "Bob";
    return 0;
}