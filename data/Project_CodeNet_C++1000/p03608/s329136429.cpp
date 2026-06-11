#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define lcm(a, b) (a)/__gcd((a),(b))*(b)
#define endl '\n'

using namespace std;

typedef long long LL;
typedef pair<int, int> P;
typedef pair<LL, LL> LP;

static const int INF = INT_MAX;
static const LL LINF = LLONG_MAX;
static const int MIN = INT_MIN;
static const LL LMIN = LLONG_MIN;
static const int MOD = 1000000007;
static const int SIZE = 200005;

const int dx[] = {0, -1, 1, 0};
const int dy[] = {-1, 0, 0, 1};

vector<int> Div(int n) {
    vector<int> ret;
    for(int i = 1; i * i <= n; ++i) {
        if(n % i == 0) {
            ret.pb(i);

            if(i * i != n) ret.pb(n / i);
        }
    }
    sort(all(ret));
    return ret;
}

int graph[205][205];
void WarshallFloyd(int sz) {
    for( int k = 1; k <= sz; ++k ) {
        for( int i = 1; i <= sz; ++i ) {
            for( int j = 1; j <= sz; ++j ) {
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

    int n, m, r;
    cin >> n >> m >> r;
    vector<int> v(r);
    for(int i = 0; i < r; ++i) {
        cin >> v[i];

    }
    sort(all(v));

    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= n; ++j) {
            graph[i][j] = INF;

        }
    }

    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = graph[b][a] = c;

    }
    WarshallFloyd(n);
    int res = INF;
    do {
        int sum = 0;
        for(int i = 0; i < r - 1; ++i) {
            sum += graph[v[i]][v[i + 1]];

        }
        res = min(res, sum);

    } while(next_permutation(all(v)));

    cout << res << endl;
    return 0;
}
