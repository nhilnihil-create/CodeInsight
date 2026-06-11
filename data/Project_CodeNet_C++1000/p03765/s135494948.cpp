#include <bits/stdc++.h>

using namespace std;

const int maxn =1e5 + 7;

int cnta[maxn][2], cntb[maxn][2], n;
string s[2];

int GetA(int u, int v, int type)
{
    return cnta[v][type] - cnta[u - 1][type];
}
int GetB(int u, int v, int type)
{
    return cntb[v][type] - cntb[u - 1][type];
}

int32_t main()
{
    auto start = chrono::steady_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen("test.inp", "r")) freopen("test.inp", "r", stdin);
    for(int id = 0; id < 2; id++)
    {
        cin >> s[id];
        s[id] = ' ' + s[id];
        for(int i = 1; i < s[id].length(); i++)
        {
            cnta[i][id] = cnta[i - 1][id];
            cntb[i][id] = cntb[i - 1][id];
            if(s[id][i] == 'A') cnta[i][id]++;
            else cntb[i][id]++;
        }
    }
    int q;
    cin >> q;
    while(q--)
    {
        int a, b, u, v;
        cin >> a >> b >> u >> v;
        int r1 = (GetA(a, b, 0) - GetB(a, b, 0)) % 3;
        if(r1 < 0) r1 += 3;
        int r2 = (GetA(u, v, 1) - GetB(u, v, 1)) % 3;
        if(r2 < 0) r2 += 3;
        if(r1 != r2)
        {
            cout << "NO" << '\n';
        }
        else cout << "YES" << '\n';
    }
    auto finish = chrono::steady_clock::now();
}