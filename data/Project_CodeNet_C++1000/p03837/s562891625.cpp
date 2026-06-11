    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;

    vector<ll> adj[200];
    ll p[150], dis[200][200];

    void solve() {
        ll n, m;
        cin >> n >> m;

        for(ll i = 1; i <= n; i++)
            for(ll j = 1; j <= n; j++)
                dis[i][j] = 1000000;

        for(ll i = 1; i <= n; i++) dis[i][i] = 0;

        ll xi[m], yi[m], di[m];
        for(ll i = 0; i < m; i++) {
            ll x, y, d;
            cin >> x >> y >> d;
            xi[i] = x, yi[i] = y, di[i] = d;
            adj[x].push_back(y);
            adj[y].push_back(x);
            dis[x][y] = d, dis[y][x] = d;
        }

        for(ll k = 1; k <= n; k++)
            for(ll i = 1; i <= n; i++)
                for(ll j = 1; j <= n; j++)
                    if(dis[i][k] + dis[k][j] < dis[i][j]) {
                        dis[i][j] = dis[i][k] + dis[k][j];
                    }
       ll cnt = m;
        for(ll i = 0; i < m; i++) {
           bool pre = false;
            for(ll k = 1; k <= n; k++) if(dis[k][xi[i]] + di[i] == dis[k][yi[i]]) pre = true;
            pre ? cnt--:0;
        }
        cout << cnt << endl;
    }

    int main() {
      cin.sync_with_stdio(0); cin.tie(0);
      cin.exceptions(cin.failbit);
      //ll ti;   cin >> ti;  while(ti--)
      solve();
      return 0;
    }
