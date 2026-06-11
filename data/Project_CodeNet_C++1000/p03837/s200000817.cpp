#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define LCM(a, b) (a) / __gcd((a), (b)) * (b)
#define CEIL(a, b) (a)/(b)+(((a)%(b))?1:0)
#define log_2(a) (log((a)) / log(2))
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
static const int SIZE = 105;

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
int graph[SIZE][SIZE];
void WarshallFloyd(int N) {
    for( int k = 0; k < N; ++k ) {
        for( int i = 0; i < N; ++i ) {
            for( int j = 0; j < N; ++j ) {
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
    for(int i = 0; i < N; ++i) {
        for(int j = i + 1; j < N; ++j) {
            graph[i][j] = graph[j][i] = INF;
        }
    }

    vector<pair<P, int>> e(M);
    for(int i = 0; i < M; ++i) {
        cin >> e[i].F.F >> e[i].F.S >> e[i].S;
        --e[i].F.F;
        --e[i].F.S;
        graph[e[i].F.F][e[i].F.S] = e[i].S;
        graph[e[i].F.S][e[i].F.F] = e[i].S;
    }

    WarshallFloyd(N);
    int res = 0;
    for(pair<P, int> edge : e) {
        if(graph[edge.F.F][edge.F.S] != edge.S) {
            ++res;
        }
    }
    cout << res << endl;

    return 0;
}
