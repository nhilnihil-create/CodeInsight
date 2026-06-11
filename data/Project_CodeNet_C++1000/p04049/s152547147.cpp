#include <bits/stdc++.h>
#define intt long long
using namespace std;
int i,j;
vector<int>g[2050];
bool used[2050];
int level[2050];
vector<pair<int,int> >e;
int n,k,res=0;
void dfs(int node)
{
    used[node] = true;
    for ( int i : g[node] )
    {
        if ( !used[i] )
        {
            level[i] = level[node] + 1;
            if ( level[i] > k/2 )
                res++;
            dfs(i);
        }
    }
}
int main()
{
    cin >> n>> k;
    for ( i = 1; i < n ;i++ )
    {
        int x,y;
        cin >> x>> y;
        g[x].push_back(y);
        g[y].push_back(x);
        if ( k % 2 )
        {
            e.push_back({x,y});
        }
    }
    int ans = 1e9;
    if ( k % 2 )
    {
        for ( pair<int,int> i : e )
        {
            for ( j = 1;  j<= n ; j++ )
            {
                level[j]=used[j]=0;
            }
            res=0;
            used[i.first] = used[i.second] = true;
            dfs(i.first);
            dfs(i.second);
            ans = min(ans,res);
        }
        cout << ans << endl;
        return 0;
    }
    for ( i =1 ; i <= n; i++ )
    {
        for ( j = 1; j <= n ;j++ )
        {
            used[j] = false;
            level[j] = 0;
        }
        res=0;
        dfs(i);
        ans = min(ans,res);
    }
    cout << ans << endl;
}
