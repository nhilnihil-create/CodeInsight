#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define rep1(i, n) for (int i = 1; i < int(n); ++i)
#define repx(i, x, n) for (int i = int(x); i < int(n); ++i)
#define rrep(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define ALL(n) begin(n), end(n)
#define IN(a, x, b) ((a) <= (x) && (x) < (b))
#define OUT(a, x, b) ((x) < (a) || (x) < (b))
typedef long long ll;
typedef long double ld;
const ll INF = 1 << 20;
const ll MOD = 1000000007;

struct Edge
{
    int to;
    int weight;
    Edge(int t, int w) : to(t), weight(w) {}
};
using Graph = vector<vector<Edge>>;

int d[110];

int main()
{
    int N, M;
    cin >> N >> M;
    Graph G(N);
    int dist[100][100], a[1010], b[1010], c[1010];
    rep(i, M)
    {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--;
        b[i]--;
    }

    rep(i, N)
    {
        rep(j, N)
        {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }
    rep(i, M)
    {
        dist[a[i]][b[i]] = min(dist[a[i]][b[i]], c[i]);
        dist[b[i]][a[i]] = min(dist[b[i]][a[i]], c[i]);
    }

    rep(k, N)
    {
        rep(i, N)
        {
            rep(j, N)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int ans = M;
    rep(i, M)
    {
        int flg = false;
        rep(j, N)
        {
            if (dist[j][a[i]] + c[i] == dist[j][b[i]])
                flg = true;
        }
        if (flg)
        {
            ans--;
        }
    }
    cout << ans << endl;

    return 0;
}
