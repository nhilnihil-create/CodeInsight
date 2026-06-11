#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define LL long long
const int N = 100000+5;
using namespace std;
int x[N];
int dp[N][50];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++) scanf("%d",&x[i]);
    int L,Q;
    scanf("%d%d",&L,&Q);
    for(int i=1; i<=n ;i++){
        int left=i+1,right=n;
        while(left<=right){
            int mid=(left+right)/2;
            if(x[mid]<=L+x[i])left=mid+1;
            else right=mid-1;
        }
        if(x[i]+L>=x[n]) dp[i][0]=n;
        else dp[i][0]=left-1;
    }
    for(int i=1; i<=30; i++) for(int j=1; j<=n; j++) dp[j][i]=dp[dp[j][i-1]][i-1];
    while(Q--){
        int a,b;
        scanf("%d%d",&a,&b);
        if(b<a) swap(a,b);
        LL res=0;
        for(int i=30; i>=0; i--){
            if(dp[a][i]<b){
                res+=(1<<i);
                a=dp[a][i];
            }
        }
        printf("%lld\n",res+1);
    }
}