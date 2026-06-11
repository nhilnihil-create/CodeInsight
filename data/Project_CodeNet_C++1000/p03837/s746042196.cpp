#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int>pa;
map<pa,int>mp;
const int N=2e5+100;
int n,m;
int a[2000],b[2000],c[2000];
int path[202][202];
void floyd()
{
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                path[i][j]=min(path[i][j],path[i][k]+path[k][j]);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
   for(int i=1;i<=n;i++)
     for(int j=1;j<=n;j++){
       if(i==j) path[i][j]=0;
       else path[i][j]=1e9;
     }
    for(int i=1;i<=m;i++){
        cin>>a[i]>>b[i]>>c[i];
        path[a[i]][b[i]]=path[b[i]][a[i]]=c[i];
    }
    floyd();
    int ans=0;
    for(int i=1;i<=m;i++){
        int f=1;
        for(int j=1;j<=n;j++){
            if(path[j][a[i]]+c[i]==path[j][b[i]]){
                f=0;
            }
        }
        if(f) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
