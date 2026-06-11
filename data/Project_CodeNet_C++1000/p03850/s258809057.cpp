#include<cstdio>
#include<algorithm>
#define maxn 100005
using namespace std;
long long pre[maxn],suf[maxn],id[maxn],ans;
int n,a[maxn],op[maxn];
char s[2];
int main()
{
    scanf("%d",&n);
    scanf("%d",&a[1]),op[1]=1,pre[1]=a[1];
    for(int i=2;i<=n;i++)
    {
        scanf("%s%d",s,&a[i]);
        op[i]=(s[0]=='+'?1:-1);
        pre[i]=pre[i-1]+a[i]*op[i];
    }
    for(int i=n;i>=1;i--) suf[i]=suf[i+1]+a[i];
    id[n+1]=n+1;
    for(int i=n;i>=1;i--)
        if(op[i+1]==-1) id[i]=i+1;
        else id[i]=id[i+1];
    for(int i=2;i<=n;i++)
        if(op[i]==-1) ans=max(ans,pre[i-1]-suf[i]+2*suf[id[i]]);
    printf("%lld",max(ans,pre[n]));
}
