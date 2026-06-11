#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

typedef long long ll;

const int MAX_N = 200001;
int par[MAX_N];
int rnk[MAX_N];

void init(int n) {
    rep(i,n) {
        par[i] = i;
        rnk[i] = 0;
    }
}

int find(int x) {
    if (par[x] == x) {
        return x;
    } else {
        return par[x] = find(par[x]);
    }
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (rnk[x] < rnk[y]) {
        par[x] = y;
    } else {
        par[y] = x;
        if (rnk[x] == rnk[y]) rnk[x]++;
    }
}

bool same(int x, int y) {
    return find(x) == find(y);
}

void solve() {
    int N, K, L, p, q;
    cin >> N >> K >> L;
    init(N);
    rep(i,K) {
        cin >> p >> q;
        unite(p - 1, q - 1);
    }
    int roads[N];
    rep(i,N) roads[i] = find(i);
    init(N);
    rep(i,L) {
        cin >> p >> q;
        unite(p - 1, q - 1);
    }
    map<pair<int, int>, int> d;
    rep(i,N) d[make_pair(roads[i], find(i))]++;
    rep(i,N) cout << d[make_pair(roads[i], find(i))] << " ";
    cout << endl;
    return;
}

int main() {
    solve();
}