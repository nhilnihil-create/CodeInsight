#include<bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> ok;
vector<vector<int>> to, ot;

void dfs0(int v) {
    ok[v] |= 1;
    for(auto i : to[v]) {
        if(ok[i] & 1)continue;
        ok[i] |= 1;
        dfs0(i);
    }
}

void dfs1(int v) {
    ok[v] |= 2;
    for(auto i : ot[v]) {
        if(ok[i] & 2)continue;
        ok[i] |= 2;
        dfs1(i);
    }
}


const ll INF = 1e18;

int main()
{
    int n, m; cin >> n >> m;
    ok.resize(n), to.resize(n), ot.resize(n);
    vector<tuple<int,int,int>> edge; //辺集合
    for(int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c; a--, b--; c = -c;
        to[a].push_back(b);
        ot[b].push_back(a);
        edge.emplace_back(a, b, c);
    }
    dfs0(0), dfs1(n - 1);

    {
        vector<ll> dist(n, INF);
        dist[0] = 0;
        bool res = 1; //更新？
        ll step = 0;
        while(res) {

            res = false;
            for(auto i : edge) {
                ll a, b, c; tie(a, b, c) = i;
                if(ok[a] != 3 || ok[b] != 3)continue; //通らない
                //cerr << "step : " << step <<  " a : " << a << " b : " << b << "dist[a] : " << dist[a] << " dist[b] : " << dist[b] << endl;
                if(dist[b] > dist[a] + c) {
                    res = true;
                    dist[b] = dist[a] + c;
                }
            }
            step++;
            if(step > 2 * n) {
                cout << "inf" << endl;
                return 0;
            }
        }
        cout << -dist[n - 1] << endl;
    }

}