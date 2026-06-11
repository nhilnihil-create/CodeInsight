#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long ll;
const int MAXN=1e5+5;

int n,L,T;
int a[MAXN],w[MAXN];
int ans[MAXN];

int main(){
    scanf("%d%d%d",&n,&L,&T);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i],&w[i]);
        if(w[i]==2) w[i]=-1;
    }
    ll cnt=0;
    for(int i=1;i<=n;i++){
        ll np=a[i]+w[i]*T;
        if(!np) continue;
        if(np>0) (cnt+=np/L)%=n;
        else (cnt+=(np+1)/L-1)%=n;
        ans[i]=(np%L+L)%L;
    }
    sort(ans+1,ans+n+1);
    cnt=(cnt+n)%n;
    for(int i=cnt+1;i<=n;i++) printf("%d\n",ans[i]);
    for(int i=1;i<=cnt;i++) printf("%d\n",ans[i]);
}
