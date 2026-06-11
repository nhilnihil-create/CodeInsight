#include<bits/stdc++.h>
#include<algorithm>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
int main()
{
    fast_io
    ll t,i,j,n,x,y;
    cin>>x>>y;
    char a[x+2][y+2];
    memset(a,'#',sizeof(a));
    for(i=0; i<x; i++)
        for(j=0; j<y; j++)
            cin>>a[i+1][j+1];
    for(i=0; i<x+2; i++)
    {

        for(j=0; j<y+2; j++)
        {
            cout<<a[i][j];

        }
        cout<<endl;
    }

    return 0;
}



