#include <bits/stdc++.h>
#define rep(i, x, y) for (int i = x; i <= y; i++)
using namespace std;

const int N = 505;
int n, a[N * N];
struct node { int x, pos; }e[N];

bool cmp(node a, node b) { return a.x < b.x; }

int main() {
    cin >> n;
    rep(i, 1, n) {
        cin >> e[i].x;
        if (a[e[i].x]) return puts("No"), 0;
        a[e[i].x] = i, e[i].pos = i;
    }
    sort(e + 1, e + n + 1, cmp);
    int now = 1;
    rep(i, 1, n) {
        rep(j, 1, e[i].pos - 1) {
            while (a[now]) ++now;
            a[now] = e[i].pos;
        }
        if (now > e[i].x) return puts("No"), 0;
    }
    rep(i, 1, n) {
        if (e[i].pos == n) continue;
        int now = e[i].x + 1;
        rep(j, 1, n - e[i].pos) {
            while (a[now]) ++now;
            a[now] = e[i].pos;
        }
        if (now > n * n) {
            // printf("%d !!\n", e[i].pos);
            return puts("No"), 0;
        }
    }
    puts("Yes");
    rep(i, 1, n * n) printf("%d ", a[i]); puts("");
    return 0;
}
