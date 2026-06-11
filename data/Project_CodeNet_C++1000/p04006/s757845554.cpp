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
#define N 100005
#define MXN 200005
int main(){
    int n,x;
    scanf("%d %d",&n,&x);
    int a[2005];
    for(int i = 0;i<n;i++)
        scanf("%d",&a[i]);
    LL ans=0;
    int b[2005];
    for(int i =0;i<n;i++)
        b[i]=a[i],ans+=a[i];
    for(int i = 1;i<n;i++){
        for(int j=0;j<n;j++){
            b[j]=min(b[j],a[(j-i+n)%n]);
        }
        LL sum=(LL)i*x;
        for(int j =0;j<n;j++)
            sum+=b[j];
        ans=min(ans,sum);
    }
    
    printf("%lld\n",ans);
}
