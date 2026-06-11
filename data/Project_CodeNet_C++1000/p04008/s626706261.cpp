#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100005;
const int LOG = 19;

int n, k, sol;
int a[MAXN], dub[MAXN], par[LOG][MAXN], bio[MAXN];
vector <int> v[MAXN];
set < pair <int, int> > st;

void dfs (int x) {
    dub[x] = 1 + dub[par[0][x]];
    st.insert({-dub[x], x});
    for (auto sus : v[x]) dfs(sus);
}

void precompute () {
    for (int i=1; i<=n; i++) {
        par[0][i] = a[i];
    }
    par[0][1] = 1;
    for (int i=1; i<LOG; i++) {
        for (int j=1; j<=n; j++) {
            par[i][j] = par[i - 1][par[i - 1][j]];
        }
    }
}

int kth (int x, int k) {
    if (k > n) return 1;
    int pot = 0;
    while (k > 0) {
        if (k & 1) x = par[pot][x];
        k /= 2;
        pot++;
    }
    return x;
}

void brisi (int x) {
    if (bio[x]) return;
    bio[x] = 1;
    st.erase({-dub[x], x});
    for (auto sus : v[x]) {
        brisi(sus);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        if (i > 1) v[a[i]].push_back(i);
    }
    if (a[1] != 1) sol++;
    precompute();
    dfs(1);
    while (!st.empty()) {
        int x = st.begin() -> second;
        if (kth(x, k) == 1) break;
        sol++;
        brisi(kth(x, k - 1));
    }
    cout << sol;
    return 0;
}
