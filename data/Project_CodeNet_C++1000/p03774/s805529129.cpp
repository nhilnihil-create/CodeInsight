#include <bits/stdc++.h>
#define pii pair<int,int>
#define eb emplace_back
#define MOD 1000000007
#define int long long
using namespace std;
#define s second
#define f first

pii a[50], b[50];
int dis(int i, int j)
{
    return abs(a[i].f - b[j].f) + abs(a[i].s - b[j].s);
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> a[i].f >> a[i].s;

    for(int i=0;i<m;i++)
        cin >> b[i].f >> b[i].s;
    
    for(int i=0;i<n;i++)
    {
        int ans, d = 1e9;
        for(int j=0;j<m;j++)
        {
            if( dis(i, j) < d )
            {
                ans = j;
                d = dis(i, j);
            }
        }
        cout << ans+1 << '\n';
    }
}