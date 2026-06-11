#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=100005;
typedef long long ll;
int n,m,p[N];
ll k;
ll a[N];
ll dist[N];
bool vis[N];
ll ans[N];
int st[N],top;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        p[i]=i;
        dist[i]=a[i]-a[i-1];
    }
    scanf("%d%lld",&m,&k);
    for(int i=1;i<=m;i++){
        int x;
        scanf("%d",&x);
        swap(p[x],p[x+1]);
    }
    for(int i=1;i<=n;i++)
        if(!vis[i]){
            top=0;
            for(int j=i;!vis[j];j=p[j])
                st[++top]=j,vis[j]=1;
            for(int j=1;j<=top;j++)
                ans[st[j]]=dist[st[(k+j-1)%top+1]];
        }
    for(int i=1;i<=n;i++)
        ans[i]+=ans[i-1];
    for(int i=1;i<=n;i++)
        printf("%lld\n",ans[i]);
}
