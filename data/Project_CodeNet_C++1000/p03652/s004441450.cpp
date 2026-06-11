#include <bits/stdc++.h>
using namespace std;
const int N=310;
int n,m,a[N][N];
#define pr pair<int,int> 
pr rnk[N];
bool v[N];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
        rnk[i].second=i;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            if(j==1) rnk[a[i][j]].first--;
        }
    int cnt=0,ans=1e9;
    while(cnt<m){
        sort(rnk+1,rnk+m+1);
        ans=min(ans,-rnk[1].first);
        v[rnk[1].second]=true;
        memset(rnk,0,sizeof(rnk));
        for(int i=1;i<=m;i++)
            rnk[i].second=i;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(!v[a[i][j]]){
                    rnk[a[i][j]].first--;
                    break;
                }
        cnt++;
    }
    printf("%d",ans);
}
