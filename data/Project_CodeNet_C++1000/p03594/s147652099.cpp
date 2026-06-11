#include <bits/stdc++.h>
using namespace std;

int m,n,d;
pair<int,int> Free[505][505];

int main()
{
    cin>>m>>n>>d;
    int ii=n,jj=1;
    for(int i=1; i<=m; i++)
    {
        int iii=ii,jjj=jj;
        for(int j=1; j<=n; j++)
        {
            Free[i][j]=make_pair(iii,jjj);
            iii--;
            jjj++;
        }
        ii++;
        jj++;
    }
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            int bi=(Free[i][j].first-1)/d%2,bj=(Free[i][j].second-1)/d%2;
            if(bi==0&&bj==0)
                cout<<'R';
            if(bi==0&&bj==1)
                cout<<'Y';
            if(bi==1&&bj==0)
                cout<<'G';
            if(bi==1&&bj==1)
                cout<<'B';
        }
        cout<<"\n";
    }
}
