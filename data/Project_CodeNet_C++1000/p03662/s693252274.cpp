#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define erep(i, a, b) for (int i = a; i <= (int)(b); ++i)
#define per(i, a, b) for (int i = (b); i > (a); --i)
#define eper(i, a, b) for (int i = ((int)(a)); i >= b; --i)
#define pb push_back
#define mp make_pair
#define INF 2000000000
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }

int n;
vector<int> g[100005];
int distF[100005], distS[100005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    fill(distF, distF + n, INF);
    fill(distS, distS + n, INF);
    rep(i, 0, n-1)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }

    queue<int> que;
    que.push(0);
    distF[0] = 0;
    while (!que.empty())
    {
        int v = que.front();
        que.pop();
        for (int nxt : g[v])
        {
            if (distF[nxt] == INF)
            {
                distF[nxt] = distF[v] + 1;
                que.push(nxt);
            }
        }
    }

    queue<int> q;
    q.push(n-1);
    distS[n-1] = 0;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int nxt : g[v])
        {
            if (distS[nxt] == INF)
            {
                distS[nxt] = distS[v] + 1;
                q.push(nxt);
            }
        }
    }

    int ans = 0;
    rep(i, 0, n) {
        if (distF[i] <= distS[i]) ans++;
        else ans--;
        // cout << distF[i] << "  " << distS[i] << endl;
    }
    printf("%s\n", ans > 0 ? "Fennec" : "Snuke");
    return 0;
}
