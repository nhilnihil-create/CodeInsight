#include <bits/stdc++.h>
typedef long long int LL;
typedef unsigned long long int ULL;
using namespace std;

// 插入此處

LL dist[1005];
LL a[2005], b[2005], c[2005];
LL INF = 1LL << 60;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i] >> c[i];
        c[i] = -c[i];
    }
    for (int i = 1; i <= n; i++) {
        dist[i] = INF; 
    }
    dist[1] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            if (dist[a[j]] == INF) {
                continue;
            } 
            if (dist[b[j]] > dist[a[j]] + c[j]) {
                dist[b[j]] = dist[a[j]] + c[j];
            }
        }
    }
    LL ans = dist[n];
    for (int j = 0; j < m; j++) {
        if (dist[a[j]] == INF) {
            continue;
        } 
        if (dist[b[j]] > dist[a[j]] + c[j]) {
            dist[b[j]] = dist[a[j]] + c[j];
        }
    }
    if (ans != dist[n]) {
        cout << "inf" << endl;
    } else {
        cout << -ans << endl;
    }
}
