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
    int n;
    cin >> n;
    int a[n];
    bool vis[n] = {0};
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        a[i]--;
    }
    int ans=1, i=0;
    bool flag=false;
    while( !vis[i] )
    {
        if( a[i] == 1 )
        {
            flag = true;
            break;
        }
        vis[i] = true;
        i = a[i];
        ans++;
    }
    if( flag )
        cout << ans;
    else
        cout << "-1";
}