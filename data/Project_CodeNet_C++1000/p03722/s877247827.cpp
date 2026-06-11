#include <iostream>
using namespace std;
struct edge { int src, dst, score; };
int main() {
    int n, m; cin >> n >> m;
    edge es[m];
    for (int i = 0; i < m; i++) {
        cin >> es[i].src >> es[i].dst >> es[i].score;
        es[i].src--; es[i].dst--;
    }
    long long d[n];
    fill(d, d+n, -1LL<<60);
    d[0] = 0;
    long long a1;
    for (int k = 0; k < 2*n; k++) {
        for (int i = 0; i < m; i++) {
            if (d[es[i].src] + es[i].score > d[es[i].dst])
                d[es[i].dst] = d[es[i].src] + es[i].score;
        }
        if (k == n) a1 = d[n-1];
    }
    if (a1 == d[n-1]) cout << a1 << endl;
    else cout << "inf\n";
}
