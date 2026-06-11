#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <cmath>

#define BEGIN(x) x.begin()
#define END(x) x.end()
#define ALL(x) BEGIN(x), END(x)
#define PAIR make_pair
#define VEC(type) vector<type >

#define FOR(i, A, B) for(auto i = (A);i != (B); i++)
#define FORD(i, A, B) for(auto i = (A);i != (B); i--)

#define READRANGE(begin, end) FOR(it, begin, end) cin >> *it
#define READVEC(V) READRANGE(BEGIN(V), END(V))

using namespace std;

typedef long long lint;
typedef pair<int, int> Pii;
typedef pair<int, lint> Pil;
typedef pair<lint, lint> Pll;
typedef pair<lint, int> Pli;

void io_init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
};

int main(int argc, char **argv)
{
    io_init();

    // Actual program code starts here.
    int N, M;
    cin >> N >> M;
    const int _inf = 1000 * 1000;
    VEC(VEC(int)) dist(N, VEC(int)(N, _inf));
    VEC(VEC(int)) edges;
    FOR(i, 0, M) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;b--;
        dist[a][b] = dist[b][a] = min(dist[a][b], c);
        edges.push_back({a, b, c});
    }

    FOR(i, 0, N)
        dist[i][i] = 0;
    FOR(i, 0, N)
        FOR(j, 0, N)
            FOR(k, 0, N)
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);

    int ret = 0;
    FOR(i, 0, M) {
        int u = edges[i][0], v = edges[i][1], c = edges[i][2];
        int good = 0;
        FOR(a, 0, N)
            FOR(b, 0, a)
                if (dist[a][b] == dist[a][u] + c + dist[v][b] ||
                        dist[a][b] == dist[a][v] + c + dist[u][b])
                    good = 1;

        if (!good)
            ret++;
    }

    cout << ret << endl;
    return 0;
};
