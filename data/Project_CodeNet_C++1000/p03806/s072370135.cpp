#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int inf=0x3f3f3f3f;
void solve(int n,int* x,int* y,int* z,int a,int b){
    int dp[444][444];
    memset(dp,0x3f,sizeof(dp));
    dp[0][0]=0;
    for(int i=0;i<n;i++){
        for(int j=400;j>=x[i];j--){
            for(int k=400;k>=y[i];k--){
                if(dp[j-x[i]][k-y[i]]!=inf){
                    dp[j][k]=min(dp[j][k],dp[j-x[i]][k-y[i]]+z[i]);
                }
            }
        }
    }
    int ans=inf;
    for(int i=1;a*i<=400&&b*i<=400;i++){
        ans=min(ans,dp[a*i][b*i]);
    }
    printf("%d\n",ans==inf?-1:ans);
}

int main(){
    int n,a,b;
    while(cin>>n>>a>>b){
        int x[40],y[40],z[40];
        for(int i=0;i<n;i++)
            cin>>x[i]>>y[i]>>z[i];
        solve(n,x,y,z,a,b);
    }
    return 0;
}
