#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,m;cin>>n>>m;

    vector<vector<int>> g(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b;cin>>a>>b;
        g[a].push_back(b);
    }

    bool ans=false;

    for(auto g1:g[1])
    {
        for(auto g2:g[g1])if(g2==n){ans=true;break;}
        if(ans)break;
    }

    puts(ans?"POSSIBLE":"IMPOSSIBLE");

    return 0;
}
