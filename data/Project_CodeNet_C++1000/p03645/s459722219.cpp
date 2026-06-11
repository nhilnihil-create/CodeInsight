#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)
int N, M;
void func()
{
    cin >> N >> M;
    vector<vector<int>> land(N + 1, vector<int>(0));
    rep(i, 0, M)
    {
        int a, b;
        cin >> a >> b;
        land[a].push_back(b);
        land[b].push_back(a);
    }
    bool v[N + 1] = {};
    queue<int> q;
    q.push(1);
    v[1] = true;
    int cnt = 0;
    while (cnt++ <= land[1].size())
    {
        int y = q.front();
        v[y] = true;
        q.pop();
        rep(i, 0, land[y].size())
        {
            int tmp = land[y][i];
            if (tmp == N)
            {
                cout << "POSSIBLE" << endl;
                return;
            }
            if (!v[tmp])
            {
                q.push(tmp);
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}
int main()
{
    func();
}