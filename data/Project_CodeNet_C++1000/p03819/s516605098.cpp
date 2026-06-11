#include <bits/stdc++.h>
#define int long long
using pii=std::pair<int,int>;
using namespace std;

const int maxm = 1e5 + 5;

int n, m, l, r, bit[maxm];

void add(int idx, int val)
{
    for(++idx; idx < maxm; idx += idx & -idx)
        bit[idx] += val;
}

int sum(int idx)
{
    int curans = 0;
    for(++idx; idx > 0; idx -= idx & -idx)
        curans += bit[idx];
    return curans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    vector<pair<int, pii>> segments;
    for(int i = 0; i < n; i++)
    {
        cin >> l >> r;
        add(l, 1);
        add(r + 1, -1);
        segments.push_back({r - l + 1, {l, r}});
    }
    sort(segments.begin(), segments.end(), greater<>());
    int always = 0;
    vector<int> ans;
    for(int i = m; i >= 1; i--)
    {
        while(always < n && segments[always].first >= i)
        {
            add(segments[always].second.first, -1);
            add(segments[always].second.second + 1, 1);
            always++;
        }
        int curans = always;
        for(int j = 1; i * j <= m; j++)
            curans += sum(i * j);
        ans.push_back(curans);
    }
    reverse(ans.begin(), ans.end());
    for(auto x : ans)
        cout << x << "\n";
    return 0;
}