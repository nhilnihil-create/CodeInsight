#include <iostream>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main(void) {
    int N, M;
    cin >> N >> M;

    const int NMAX = 1000;
    const int MMAX = 2000;
    int a[MMAX], b[MMAX];
    ll c[MMAX];

    for (int i = 0; i < M; i++) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--;
        b[i]--;
        c[i] = -c[i];
    }

    ll dist[NMAX];
    for (int i = 0; i < N; i++) {
        dist[i] = INF;
    }

    dist[0] = 0;

    for (int loop = 0; loop < N-1; loop++) {
        for (int i = 0; i < M; i++) {
            if (dist[a[i]] == INF) continue;
            if (dist[b[i]] > dist[a[i]]+c[i]) {
                dist[b[i]] = dist[a[i]]+c[i];
            }
        }
    }
    ll ans = dist[N-1];
    bool negative[NMAX];
    for (int i = 0; i < N; i++) {
        negative[i] = false;
    }
    for (int loop = 0; loop < N; loop++) {
        for (int i = 0; i < M; i++) {
            if (dist[a[i]] == INF) continue;
            if (dist[b[i]] > dist[a[i]]+c[i]) {
                dist[b[i]] = dist[a[i]]+c[i];
                negative[b[i]] = true;
            }
            if (negative[a[i]] == true) {
                negative[b[i]] = true;
            }
        }
    }

    if (negative[N-1] == true) {
        cout << "inf" << endl;
    } else {
        cout << -ans << endl;
    }

    return 0;
}