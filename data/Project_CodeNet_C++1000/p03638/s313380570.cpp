#include<bits/stdc++.h>
using namespace std;
int ara[104][104];
int r,c;
int C[10004];
int fx[]={0,1,0,-1,0,1,0,-1};
int fy[]={1,0,-1,0,1,0,-1,0};
bool vis[105][105];
void dfs(int x,int y,int i)
{
//    cout<<x<<" "<<y<<" "<<i<<" "<<C[i]<<endl;
    ara[x][y]=i;
    vis[x][y]=1;
    for(int k=0;k<8;k++)
    {
        int xx=x+fx[k];
        int yy=y+fy[k];
        if(xx>=0&&yy>=0&&xx<r&&yy<c)
        {
            if(vis[xx][yy]==0)
            {
                if(C[i]==0)i++;
                C[i]--;
                dfs(xx,yy,i);
            }
        }
    }
    return;
}

int main()
{
        memset(ara,0,sizeof ara);
        memset(C,0,sizeof C);
        cin>>r>>c;
        int n;cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>C[i];
        }
        C[1]--;
        dfs(0,0,1);
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                cout<<ara[i][j];
                if(j<c-1)cout<<" ";
            }
            cout<<endl;
        }

}
/*
6 6
6
1 4 2 8 15 6

5 5
6
1 4 2 3 12 3

5 5
5
5 5 5 5 5
*/
