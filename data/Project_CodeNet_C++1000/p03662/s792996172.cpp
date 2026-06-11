#include<bits/stdc++.h>
#define F first
#define S second
#define endl '\n'
#define lcm( a, b ) ((a)/__gcd(a,b)*(b))
#define MP make_pair
#define pb push_back
#define all(x) (x).begin(),(x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> P;
typedef pair<int, P> i_P;
typedef pair< LL, LL > L_P;

const int INF = INT_MAX;
const int MIN = INT_MIN;
const LL LINF = LLONG_MAX;
const int MOD = 1000000000 + 7;
const int SIZE = 100005;

void bfs( bool visit[], int dist[], int s );

vector< int > graph[SIZE];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    int w_dist[SIZE];
    int b_dist[SIZE];
    bool b_visit[SIZE];
    bool w_visit[SIZE];
    cin >> n;

    for( int i = 1; i <= n; ++i ) {
        w_dist[i] = b_dist[i] = 0;
        b_visit[i] = w_visit[i] = false;

    }

    for( int i = 0; i < n - 1; ++i ) {
        int a, b;
        cin >> a >> b;
        graph[a].pb( b );
        graph[b].pb( a );

    }

    bfs( w_visit, w_dist, 1 );
    bfs( b_visit, b_dist, n );
    int w_res = 0, b_res = 0;
    for( int i = 1; i <= n; ++i ) {
        if( w_dist[i] <= b_dist[i] ) ++w_res;
        else if( w_dist[i] > b_dist[i] ) ++b_res;

    }

    if( w_res > b_res ) cout << "Fennec";
    else cout << "Snuke";
    cout << endl;

    return 0;
}

void bfs( bool visit[], int dist[], int s ) {
    queue< P > q;
    q.push( MP( s, 0 ) );

    while( !q.empty() ) {
        P p = q.front();
        visit[p.F] = true;
        dist[p.F] = p.S;
        q.pop();

        for( int i = 0; i < graph[p.F].size(); ++i ) {
            if( !visit[graph[p.F][i]] ) {
                q.push( MP( graph[p.F][i], p.S + 1 ) );

            }
        }
    }

    return;
}

