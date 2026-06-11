#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<iostream>
#include<map>
#include<cstring>
#define INF 0x3f3f3f3f
using namespace std;
vector <tuple<int,int,int>>relation;
set<int> pa;
set<int> pb;
int n,ma,mb,suma,sumb,a[50],b[50],c[50],maxc,maxa,maxb,ans=INF;
int dp[45][405][405];
int main(){
    scanf("%d%d%d",&n,&ma,&mb);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
        maxc+=c[i];
        maxa+=a[i];
        maxb+=b[i];
    }
    for(int i=0;i<=n;i++)
        for(int j=0;j<=400;j++)
            for(int k=0;k<=400;k++){
                dp[i][j][k]=INF;
            }
    for(int i=0;i<=n;i++)
    dp[i][0][0]=0;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=maxa;j++)
            for(int k=0;k<=maxb;k++){
                dp[i][j][k]=dp[i-1][j][k];
                if(dp[i-1][j-a[i]][k-b[i]]==INF)
                    continue;
                if(j>=a[i]&&k>=b[i])
                    dp[i][j][k]=min(dp[i][j][k],dp[i-1][j-a[i]][k-b[i]]+c[i]);
                /*if(dp[i][j][k]!=INF)
                printf("dp[%d][%d][%d]=%d\n",i,j,k,dp[i][j][k]);*/
            }
    for(int i=1;i<=maxa;i++)
        for(int j=1;j<=maxb;j++)
            if(i*mb==j*ma){
                ans=min(ans,dp[n][i][j]);
            }
    if(ans==INF)
        ans=-1;
    printf("%d",ans);
}
