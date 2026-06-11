#include <iostream>
#include <vector>
using namespace std;
const long long MIN = -1e18;

struct edge {
    int from, to;
    long long dist;
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> score(n, MIN);
    vector<edge> es(m);
    for (int i=0; i<m; ++i) {
        int a, b; long long c;
        cin >> a >> b >> c;
        a--; b--;
        es[i].from = a;
        es[i].to = b;
        es[i].dist = c;
    }
    score[0] = 0;
    for (int i=0; i<n-1; ++i) {
        for (edge e: es) {
            int now = e.from;
            int next = e.to;
            if (score[now] == MIN) continue;
            if (score[next] < score[now] + e.dist) {
                score[next] = score[now] + e.dist;
            }
        }
    }
    vector<bool> is_pos(n, false);
    for (int i=0; i<n; ++i) {
        for (edge e: es) {
            int now = e.from;
            int next = e.to;
            if (score[now] == MIN) continue;
            if (score[next] < score[now] + e.dist) {
                score[next] = score[now] + e.dist;
                is_pos[next] = true;
            }
            if (is_pos[now]) is_pos[next] = true;
        }
    }
    if (is_pos[n-1]) cout << "inf" << endl;
    else cout << score[n-1] << endl;
}