#include<bits/stdc++.h>
using namespace std;
const long long MAX = 101, INF = 1e9;

long long n, M[MAX][MAX];

void init(){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            M[i][j] = INF;
        }
    }
}
int main(){
    int e, ans = 0;
    cin >> n >> e;
    init();
    vector<pair<int, pair<int, int>>> v;
    for (int i = 0; i < e; i++)
    {
        int s, t, u;
        cin >> s >> t >> u;
        M[s][t] = M[t][s] = u;
        v.push_back(make_pair(s, make_pair(t, u)));
    }
    for (int i = 1; i <= n; i++)
        M[i][i] = 0;
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (M[i][k] == INF)continue;
            for (int j = 1; j <= n; j++)
            {
                if (M[k][j] == INF) continue;
                M[i][j] = min(M[i][j], M[i][k] + M[k][j]);
            }
        }
    }
    for (auto x : v){
        ans += (M[x.first][x.second.first] != x.second.second) ? 1 : 0;
    }
    cout << ans << endl;
}