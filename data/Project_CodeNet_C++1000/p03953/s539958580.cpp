#include <bits/stdc++.h>

using namespace std;

long long y[100010];
long long res_y[100010];

vector<int> apply(vector<int> p, vector<int> q) {
    vector<int> c(p.size(), -1);
    for (int i = 0; i < q.size(); i++) {
        c[i] = p[q[i]];
    }
    return c;
}

void solve(long long N, vector<long long> x, long long M, long long K, vector<long long> a) {
    for (int i = 0; i < M; i++) a[i]--;
    vector<int> p(N - 1);
    for (int i = 0; i < N - 1; i++) p[i] = i;

    vector<int> q = p;

    for (int i = 0; i < M; i++) {
        swap(p[a[i]], p[a[i] - 1]);
    }
    for (int bit = 0; bit < 63; bit++) {
        if (K >> bit & 1) {
            q = apply(q, p);
        }
        p = apply(p, p);
    }

    for (int i = 0; i < N - 1; i++) y[i] = x[i + 1] - x[i];
    for (int i = 0; i < N - 1; i++) {
        res_y[i] = y[q[i]];
    }

    long long ans = x[0];
    for (int i = 0; i < N - 1; i++) {
        cout << ans << endl;
        ans += res_y[i];
    }
    cout << ans <<  endl;


}

int main() {
    long long N;
    scanf("%lld", &N);
    vector<long long> x(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &x[i]);
    }
    long long M;
    scanf("%lld", &M);
    long long K;
    scanf("%lld", &K);
    vector<long long> a(M);
    for (int i = 0; i < M; i++) {
        scanf("%lld", &a[i]);
    }
    solve(N, x, M, K, a);
    return 0;
}

