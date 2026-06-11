#include<bits/stdc++.h>
#include<algorithm>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
int main()
{
    fast_io
    ll t,i,j,h,w;
    cin>>h>>w;
    char a[h][w];
    for(i=0; i<h; i++)
        for(j=0; j<w; j++)
            cin>>a[i][j];
    for(i=0; i<h; i++)
    {
        for(t=0; t<w; t++)
            cout<<a[i][t];
        cout<<endl;

        for(j=0; j<w; j++)
            cout<<a[i][j];
        cout<<endl;

    }
    return 0;
}



