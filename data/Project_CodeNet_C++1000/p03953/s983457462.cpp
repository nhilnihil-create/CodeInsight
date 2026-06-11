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
int go[100005][60];
int main(){
    int n;
    scanf("%d",&n);
    LL a[100005];
    LL ori[100005];
    for(int i = 1;i<=n;i++){
       scanf("%lld",&a[i]);
      //  a[i]=rand();
       // ori[i]=a[i];
    }
    LL dis[100005];
    for(int i = 1;i<n;i++){
        dis[i]=a[i+1]-a[i];
    }
    LL m,k;
    scanf("%lld %lld",&m,&k);
    int q[100005];
    int aa[100005];
    for(int i = 1;i<n;i++)
        aa[i]=i;
    for(int i = 1;i<=m;i++){
        scanf("%d",&q[i]);
        swap(aa[q[i]],aa[q[i]-1]);
    }
    for(int i = 1;i<n;i++){
        go[aa[i]][0]=i;
    }
    for(int i = 1;i<60;i++){
        for(int j=1;j<n;j++){
            go[j][i]=go[go[j][i-1]][i-1];
        }
    }
    int ans[100005];
    for(int j = 1;j<n;j++){
        int now=j;
        for(int i=0;i<60;i++){
            if((1ll<<i)&k)now=go[now][i];
        }
        ans[now]=j;
     //   printf("%d\n",now);
    }
    printf("%lld\n",a[1]);
    LL now=a[1];
    for(int i = 1 ;i<n;i++){
        now+=dis[ans[i]];
        printf("%lld\n",now);
    }
}
/*

b[i]*K!/(i)!*(K-i)!
*/