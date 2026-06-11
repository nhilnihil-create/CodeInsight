#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define dep(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int maxn=2e5+5;
//const double pi=acos(-1.0);
//const double eps=1e-9;
//const ll mo=1e9+7;
int n,m,k,l,q;
int a[maxn],c[maxn];
int f[maxn][25];
int ans,tmp,cnt;
int flag;
char s[maxn];
bool ok[maxn];
int main()
{
    int T,cas=1;
    //scanf("%d",&T);
    while(scanf("%d",&n)!=EOF)
    {
        rep(i,0,n) c[i]=1;
        int j=1;
        rep(i,1,n) scanf("%d",&a[i]);
        scanf("%d",&l);
        rep(i,0,20)
        for(int j=0;j<=n;j++)
        f[j][i]=inf;
        rep(i,1,n){
            while(a[i]>a[j]+l) {f[j][0]=i-1;j++;}
        }
        rep(i,1,20)
        {
            c[i]=c[i-1]<<1;
            for(int j=1;j<=n;j++)
            if(f[j][i-1]!=inf){
                //cout<<f[j][i-1]<<endl;
                f[j][i]=f[f[j][i-1]][i-1];
            }
        }
        ans=0;
        scanf("%d",&q);
        rep(t,1,q)
        {
            int x,y,ans=0;
            scanf("%d%d",&x,&y);
            if(x>y) swap(x,y);
            dep(i,20,0)
            {
                if(f[x][i]<y)
                {
                    x=f[x][i];
                    ans+=c[i];
                }
            }
            printf("%d\n",ans+1);
        }
    }
    return 0;
}
