#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef pair<int,int> PII;


long long n, m, k, a[1<<20], ans[1<<20], d[1<<20], p[1<<20];

void mul(long long a[], long long b[]) {
    static long long c[1<<20];
    for (int i = 1; i < n; i++) c[i] = a[b[i]];
    for (int i = 1; i < n; i++) a[i] = c[i];
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        d[i+1] -= a[i], d[i] += a[i];
        ans[i+1] = p[i+1] = i+1;
    }
    cin >> m >> k;
    for (int i = 0; i < m; i++) {
        int u;
        cin >> u;
        swap(p[u],p[u-1]);
    }
    for (long long x = k; x; x>>=1) { if (x&1) mul(ans,p); mul(p,p); }
    for (int i = 1; i < n; i++) a[i] = a[i-1] + d[ans[i]];
    for (int i = 0; i < n; i++) cout << a[i] << '\n';
}
