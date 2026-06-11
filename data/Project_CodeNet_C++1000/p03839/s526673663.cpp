#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define KK 500
#define MXN 200005
int main(){
    LL pre[100005];
    LL suf[100005];
    LL sum[100005];
    int a[100005];
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i = 1;i<=n;i++)
        scanf("%d",&a[i]);
    pre[0]=0;
    suf[n+1]=0;
    sum[0]=0;
    for(int i = 1;i<=n;i++){
        pre[i]=pre[i-1]+max(a[i],0);
        sum[i]=sum[i-1]+a[i];
    }
    for(int i = n;i>=1;i--){
        suf[i]=suf[i+1]+max(a[i],0);
    }
    LL ans=0;
    for(int i=1;i<=n-k+1;i++){
        ans=max(ans,pre[i-1]+suf[i+k]+max(sum[i+k-1]-sum[i-1],0ll));
    }
    printf("%lld\n",ans);
}
/*
1441152
*/