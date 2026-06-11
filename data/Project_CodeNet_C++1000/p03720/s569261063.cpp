#include <bits/stdc++.h>
#define pii pair<int,int>
#define eb emplace_back
#define MOD 1000000007
#define int long long
using namespace std;
#define s second
#define f first

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int a[n] = {0};
    for(int i=0;i<m;i++)
    {
        int x, y;
        cin >> x >> y;
        a[x-1]++;
        a[y-1]++;
    }
    for(int i=0;i<n;i++)
        cout << a[i] << '\n';
}