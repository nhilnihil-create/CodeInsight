#include <bits/stdc++.h>
#define MAX_N 200000L
using namespace std;

int find(int x, int par[], int ran[]) {
    if (x == par[x])
        return x;
    return par[x] = find(par[x], par, ran);
}

void unite(int x, int y, int par[], int ran[]) {
    x = find(x, par, ran);
    y = find(y, par, ran);
    if (x == y)
        return;
    if (ran[x] < ran[y]) {
        par[x] = par[y];
    } else {
        par[y] = par[x];
        if (ran[x] == ran[y])
            ran[x]++;
    }
}


int main() {
    int n, k, l;
    cin >> n >> k >> l;
    int r_par[n + 1], r_rank[n + 1], t_par[n + 1], t_rank[n + 1];
    for (int i = 1; i <= n; i++) {
        r_par[i] = i;
        r_rank[i] = 0;
        t_par[i] = i;
        t_rank[i] = 0;
    }
    for (int i = 0; i < k; i++) {
        int p, q;
        cin >> p >> q;
        unite(p, q, r_par, r_rank);
    }
    for (int i = 0; i < l; i++) {
        int r, s;
        cin >> r >> s;
        unite(r, s, t_par, t_rank);
    }
    unordered_map<long, int> mp;
    for (int i = 1; i <= n; i++) {
        mp[MAX_N * find(i, r_par, r_rank) + find(i, t_par, t_rank) - 1]++;
    }
    for (int i = 1; i <= n; i++) {
        cout << mp[MAX_N * find(i, r_par, r_rank) + find(i, t_par, t_rank) - 1] << ((i == n) ? '\n' : ' ');
    }
    return 0;
}
