#include <bits/stdc++.h>
#define int long long 

using namespace std;

const int maxn = 3e5 + 7;
vector<int> add[maxn], del[maxn];
int sum1[maxn], sum2[maxn], ans[maxn], n, l[maxn], r[maxn], m;
vector<int> vt[maxn];

int BIT[maxn];

void Update(int pos, int val)
{
    for(; pos < maxn; pos += pos & -pos)
    {
        BIT[pos] += val;
    }
}

int Query(int pos)
{
    int ans = 0;
    for(; pos > 0; pos -= (pos & -pos))
    {
        ans += BIT[pos];
    }
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen("test.inp", "r")) freopen("test.inp", "r", stdin);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> l[i] >> r[i];
        add[l[i]].push_back(l[i]);
        del[r[i]].push_back(l[i]);
    }
    for(int i = 1; i <= m; i++)
    {
        for(int j = i; j <= m; j+= i)
        {
            vt[j].push_back(i);
        }
    }
    for(int i = 1; i <= m; i++)
    {
        for(auto j: add[i]) Update(j, 1);
        for(auto j: vt[i])
        {
            ans[j] += Query(i) - Query(i - j);
        }
        for(auto j: del[i]) Update(j, -1);
    }
    for(int i = 1; i <= m; i++) cout << ans[i] << '\n';
}