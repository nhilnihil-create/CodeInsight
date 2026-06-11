#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)n; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<pi, pi> pp;
typedef pair<ll, ll> pl;
const double EPS = 1e-9;
const ll MOD = 1000000007;
const int inf = 1 << 30;
const ll linf = 1LL << 60;

int n, m;
vector<int> e[100000];
bool saw[100000];
int ans[300000];
int st = 150000, en = 150000;

int main() {
    cin >> n >> m;
    rep(i,m) {
        int a, b; cin >> a >> b;
        a--; b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    saw[0] = true;
    ans[en++] = 0;
    while (true) {
        int p = ans[en-1];
        bool end = true;
        for (int t: e[p]) {
            if (saw[t]) continue;
            ans[en++] = t;
            saw[t] = true;
            end = false;
            break;
        }
        if (end) break;
    }
    while (true) {
        int p = ans[st];
        bool end = true;
        for (int t: e[p]) {
            if (saw[t]) continue;
            ans[--st] = t;
            saw[t] = true;
            end = false;
            break;
        }
        if (end) break;
    }
    cout << en-st << endl;
    for (int i = st; i < en; i++) {
        cout << ans[i]+1;
        if (i == en-1) cout << endl;
        else cout << " ";
    }
}