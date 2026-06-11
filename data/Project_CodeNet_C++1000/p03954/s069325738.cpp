#include"cstdio"
#include"cstring"
#include"iostream"
#include"algorithm"
using namespace std;

const int MAX=2e5+1;

struct p{int x,L;}c[MAX],d[MAX];
int n;
int a[MAX],b[MAX];

bool look(int mid)
{
    int num1=0,num2=0,A1=0,A0=0,L0=0,L1=0,T1,T0;
    for(int i=1;i<2*n;++i) if(a[i]>=mid) b[i]=1,++A1;else b[i]=0,++A0;
    for(int i=1;i<n<<1;++i){
        if(!b[i]){
          	L1=0,++L0;
          	if(L0==1) T0=i;
          	if(L0==2) d[++num2].x=T0;
          	if(L0>1) d[num2].L=L0;
        }else{
          	L0=0,++L1;
          	if(L1==1) T1=i;
          	if(L1==2) c[++num1].x=T1;
          	if(L1>1) c[num1].L=L1;
        }
    }if(!num1&&!num2) return A1>A0;int minn=1e9;
    for(int i=1;i<=num1;++i) if(minn>min(abs(c[i].x-n),abs(c[i].x+c[i].L-n-1))) minn=min(abs(c[i].x-n),abs(c[i].x+c[i].L-n-1));
    for(int i=1;i<=num2;++i) if(minn>min(abs(d[i].x-n),abs(d[i].x+d[i].L-n-1))) return 0;
    return 1;
}

int main()
{
    scanf("%d",&n);for(int i=1;i<2*n;++i) scanf("%d",&a[i]);
    int l=1,r=n*2-1,ans;
    while(l<=r){
        int mid(l+r>>1);
        if(look(mid)) l=mid+1,ans=mid;
        else r=mid-1;
    }printf("%d\n",ans);
    return 0;
}