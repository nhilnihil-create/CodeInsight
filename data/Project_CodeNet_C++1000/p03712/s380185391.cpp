#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    char a[n+2][m+2]= {};
    memset(a,'#',sizeof(a));
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin>>a[i][j];
    for(int i=0; i<=n+1; i++)
    {
        for(int j=0; j<=m+1; j++)
        {
            cout<<a[i][j];
        }
        cout<<'\n';
    }
    return 0;
}


