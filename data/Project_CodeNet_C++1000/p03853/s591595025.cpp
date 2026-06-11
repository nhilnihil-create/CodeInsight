#include <bits/stdc++.h>
using namespace std;

char c[110][110];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int h,w;
    cin>>h>>w;

    for(int i=0;i<h;i++)for(int j=0;j<w;j++)cin>>c[i][j];

    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)cout<<c[i][j];
        cout<<"\n";
        for(int j=0;j<w;j++)cout<<c[i][j];
        cout<<"\n";
    }

    return 0;
}
