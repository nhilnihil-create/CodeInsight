#include <bits/stdc++.h>
#define int long long 

using namespace std;

const int maxn = 1e5 + 7;

int n, a[maxn], ans[maxn], curval;

vector<pair<int, int>> vt;
set<int> st;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen("test.inp", "r")) freopen("test.inp", "r", stdin);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        vt.emplace_back(a[i], i);
    }
    sort(vt.begin(), vt.end(), greater<pair<int, int>>());
    int cur = 1;
    st.insert(vt[0].second);
    for(; cur < vt.size(); cur++)
    {
        if(vt[cur].first == vt[cur - 1].first) st.insert(vt[cur].second);
        else break;
    }
    curval = vt[cur - 1].first;
    while(cur < vt.size())
    {
        ans[*st.begin()] += (curval - vt[cur].first) * st.size();
        curval = vt[cur].first;
        for(; cur < vt.size() && vt[cur].first == curval; cur++)
        {
            st.insert(vt[cur].second);
        }
    }
    ans[*st.begin()] += (curval - 0) * st.size();
    for(int i = 1; i <= n; i++) cout << ans[i] << '\n';
}