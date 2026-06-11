#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            a[i][j]--;
        }
    }
    vector<int> pos(n, 0);
    int ans = n;
    set<int> s;
    for(int i = 0; i < m-1; i++)
    {
        vector<int> cnt(m, 0);
        for(int j = 0; j < n; j++)
        {
            int p = pos[j];
            int c = a[j][p];
            cnt[c]++;
        }
        int ma = 0;
        int color = 0;
        for(int j = 0; j < m; j++)
        {
            if(cnt[j] > ma)
            {
                ma = cnt[j];
                color = j;
            }
        }
        s.insert(color);
        ans = min(ans, ma);
        for(int j = 0; j < n; j++)
        {
            int p = pos[j];
            int c = a[j][p];
            while(s.find(c) != s.end())
            {
                pos[j]++;
                c = a[j][pos[j]];
            }
        }
    }
    cout << ans << endl;
}
