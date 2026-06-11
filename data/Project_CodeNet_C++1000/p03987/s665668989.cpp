#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()

vector<vector<int>> lookup;
int L;

void build_sparse_table(int N, vector<ll>& a) {
    int n = 1;
    L = 0;
    while (n <= N) {
        n <<= 1;
        L++;
    }
    lookup = vector<vector<int>>(N, vector<int>(L));
    REP(i, N) {
        lookup[i][0] = a[i];
    }
    for (int j = 1; j < L; j++) {
        REP(i, N - (1 << j) + 1) {
            lookup[i][j] = min(lookup[i][j-1], lookup[i + (1 << (j-1))][j-1]);
        }
    }
}

int query(int l, int r) {
    int lb = 0, ub = L + 1;
    while (ub - lb > 1) {
        int m = (lb + ub) / 2;
        if ((1 << m) < r - l) lb = m;
        else ub = m;
    }
    return min(lookup[l][lb], lookup[r - (1 << lb)][lb]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<ll> a(N);
    REP(i, N) cin >> a[i];
    build_sparse_table(N, a);

    vector<ll> left(N);
    REP(i, N) {
        int lb = -1, ub = i;
        while (ub - lb > 1) {
            int m = (lb + ub) / 2;
            if (query(m, i) < a[i]) lb = m;
            else ub = m;
        }
        left[i] = i - lb;
    }
    vector<int> right(N);
    REP(i, N) {
        int lb = i, ub = N+1;
        while (ub - lb > 1) {
            int m = (lb + ub) / 2;
            if (query(i, m) < a[i]) ub = m;
            else lb = m;
        }
        right[i] = lb - i;
    }
    ll ans = 0;
    REP(i, N) ans += left[i] * right[i] * a[i];
    cout << ans << endl;
}