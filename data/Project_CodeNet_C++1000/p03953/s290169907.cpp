// Why am I so dumb? :c
// chrono::system_clock::now().time_since_epoch().count()
#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair

#define all(x) (x).begin(), (x).end()

#define fi first
#define se second

using namespace std;

typedef long long ll;   

const int MAXN = (int)1e5 + 5;

ll arr[MAXN], d[MAXN];

bool used[MAXN];

int perm[MAXN];

int conv[MAXN];

int id[MAXN];

int n, m;

ll k;

void solve() {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &arr[i]);
    }

    for (int i = 1; i < n; ++i) {
        d[i] = arr[i + 1] - arr[i];
    }

    scanf("%d %lld", &m, &k);

    for (int i = 1; i <= m; ++i) {
        scanf("%d", &id[i]);
    }

    for (int i = 1; i < n; ++i) {
        conv[i] = i;
    }

    for (int i = 1; i <= m; ++i) {
        swap(conv[id[i] - 1], conv[id[i]]);
    }

    for (int i = 1; i < n; ++i) {
        if (!used[i]) {
            vector<int> cyc;
            int cur = i;

            for (int cur = i; !used[cur]; cur = conv[cur]) {
                used[cur] = 1;
                cyc.pb(cur);
            }               

            for (int j = 0; j < cyc.size(); ++j) {
                perm[cyc[j]] = cyc[(j + k) % cyc.size()];
            }            
        }
    }         

    for (int i = 2; i <= n; ++i) {
        arr[i] = arr[i - 1] + d[perm[i - 1]];
    }

    for (int i = 1; i <= n; ++i) {
        printf("%lld\n", arr[i]);
    }
}

int main() {
    int tt = 1;

    while (tt--) {
        solve();
    }

    return 0;
}