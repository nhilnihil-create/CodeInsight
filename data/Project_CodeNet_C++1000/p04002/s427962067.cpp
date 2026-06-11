#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
using lint = long long int;

int H, W, N;
vector<P> p;

int count(int x, int y)
{
    if (x <= 0 || y <= 0 || x >= H-1 || y >= W-1) return 0;
    int ans = 0;
    for (int i=-1; i<=1; i++)
    {
        for (int j=-1; j<=1; j++)
        {
            ans += binary_search(p.begin(), p.end(), P(x+i, y+j));
        }
    }
    return ans;
}

int main()
{
    cin >> H >> W >> N;
    for (int i=0; i<N; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        p.push_back(P(a, b));
    }
    sort(p.begin(), p.end());

    vector<set<P>> ans(9);

    for (int i=0; i<N; i++)
    {
        for (int x=-1; x<=1; x++)
        {
            for (int y=-1; y<=1; y++)
            {
                int n = count(p[i].first+x, p[i].second+y);
                if (n) ans[n-1].insert(P(p[i].first+x, p[i].second+y));
            }
        }
    }
    lint ans0 = (lint)(H-2) * (W-2);
    for (auto v : ans) ans0 -= v.size();
    cout << ans0 << endl;
    for (auto v : ans) cout << v.size() << endl;
}
