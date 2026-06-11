/*Program from Luvwgyx*/
#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define int long long
#define fir first
#define sec second
#define pi pair<int ,int >
#define mp(x,y) make_pair(x,y)
using namespace std;
const int inf=1e18;
const int maxn=3e2+10;
int n,m,ans,pos[maxn],cnt[maxn],vis[maxn],a[maxn][maxn];
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void print(int x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)print(x/10);
    putchar(x%10+'0');
}
void write(int x){print(x);puts("");}
signed main(){
    n=read();m=read();ans=inf;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)a[i][j]=read();
    for(int i=1;i<=n;i++)pos[i]=1;
    while(1){
        int mx=0,now=0;
        for(int i=1;i<=n;i++){
            cnt[a[i][pos[i]]]++;
            if(cnt[a[i][pos[i]]]>mx)mx=cnt[a[i][pos[i]]],now=a[i][pos[i]];
        }ans=min(ans,mx);vis[now]=1;bool flag=0;//write(mx);
        for(int i=1;i<=n;i++)while(vis[a[i][pos[i]]])pos[i]++;
        for(int i=1;i<=n;i++)if(pos[i]<=m){flag=1;break;}
        if(!flag)break;memset(cnt,0,sizeof(cnt));
    }write(ans);
    return 0;
}
