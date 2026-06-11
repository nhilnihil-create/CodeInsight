#include<bits/stdc++.h>
using namespace std;
const int N=333;
int n,m,a[N][N],ans,p[N],cnt[N];bool vis[N];
int main(){
    scanf("%d%d",&n,&m);ans=n;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)p[i]=1;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++)cnt[j]=0;
        for(int j=1;j<=n;j++)cnt[a[j][p[j]]]++;
        int mx=0,q=0;
        for(int j=1;j<=m;j++)if(cnt[j]>mx)mx=cnt[j],q=j;
        ans=min(ans,mx);vis[q]=1;
        for(int j=1;j<=n;j++)while(vis[a[j][p[j]]])p[j]++;
    }
    cout<<ans;
    return 0;
}