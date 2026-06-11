#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define LCM(a, b) (a) / __gcd((a), (b)) * (b)
#define CEIL(a, b) (a)/(b)+(((a)%(b))?1:0)
#define ln '\n'

using namespace std;
using LL = long long;
using ldouble = long double;
using P = pair<int, int>;
using LP = pair<LL, LL>;

static const int INF = INT_MAX;
static const LL LINF = LLONG_MAX;
static const int MIN = INT_MIN;
static const LL LMIN = LLONG_MIN;
static const int MOD = 1e9 + 7;

const int dx[] = {0, -1, 1, 0};
const int dy[] = {-1, 0, 0, 1};

vector<LL> Div(LL n) {
    vector<LL> ret;
    for(LL i = 1; i * i <= n; ++i) {
        if(n % i == 0) {
            ret.pb(i);
            if(i * i != n) ret.pb(n / i);
        }
    }
    sort(all(ret));
    return ret;
}

int graph[105][105];

void WarshallFloyd(int SIZE) {
    for( int k = 1; k <= SIZE; ++k ) {
        for( int i = 1; i <= SIZE; ++i ) {
            for( int j = 1; j <= SIZE; ++j ) {
                if( graph[i][k] == INF || graph[k][j] == INF ) {
                    continue;

                }
                graph[i][j] = min( graph[i][j], 
                                    graph[i][k] + graph[k][j] );

            }
        }
    }
    return;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            if(i == j) graph[i][j] = 0;
            else graph[i][j] = INF;
        }
    }

    vector<P> g[105];
    while(M--) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = graph[b][a] = c;
        g[a].pb(MP(b, c));
    }

    WarshallFloyd(N);

    int c = 0;
    for(int i = 1; i <= N; ++i) {
        for(int j = 0; j < g[i].size(); ++j) {
            P p = g[i][j];
            if(graph[i][p.F] != p.S) ++c;
        }
    }
    cout << c << endl;

    return 0;
}

