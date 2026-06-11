#include<bits/stdc++.h>
using namespace std;
#define oo (long long)1e18
#define ll long long
#define setdp memset(dp,-1,sizeof(dp))
const ll mod = 1e9+7;
void _IOS(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);cin.sync_with_stdio(0);}
#define PI 3.14159265359
int sx,sy,tx,ty;

struct threeElements{
int _1st,_2nd,_3rd;
};
vector<vector<int>>adj(10);
int sum,n,m,visited[11];
void dfs(int i){
    visited[i]=1;
    int flag=1;
    for(int j=1;j<=n;++j){
        if(!visited[j]){
            flag=0;
        }
    }
    if(flag){
        sum++;
        return;
    }
    for(auto x:adj[i]){
        if(!visited[x]){
            dfs(x);
            visited[x]=0;
        }
    }
}
int main()
{
   // freopen ("jumping.in","r",stdin);
   _IOS();
   //18:17
   cin>>n>>m;
   char g[100][100],h[100][100];
   for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
        cin>>g[i][j];
   for(int i=0;i<m;i++)
    for(int j=0;j<m;j++)
        cin>>h[i][j];
    for(int i=0;i<n-m+1;i++)
        for(int j=0;j<n-m+1;j++)
        {
            bool f=1;
            for(int k=0;k<m;k++)
            {
                for(int z=0;z<m;z++)
                {
                    if(g[i+k][j+z]!=h[k][z])
                        f=0;
                }
            }
            if(f)
            {
                cout<<"Yes";
                return 0;
            }
        }
    cout<<"No";

}
