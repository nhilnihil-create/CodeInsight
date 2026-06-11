/*Program from Luvwgyx*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#define int long long
using namespace std;
const int maxn=1e5+10;
int n,m,K,a[maxn],X[maxn],nxt[maxn],ans[maxn],tmp[maxn];
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
void write(int x){print(x);puts(".0");}
signed main(){
    n=read();
    for(int i=1;i<=n;i++)tmp[i]=read(),X[i]=tmp[i]-tmp[i-1];
    m=read();K=read();
    for(int i=1;i<=m;i++)a[i]=read();
    for(int i=1;i<=n;i++)nxt[i]=i;
    for(int i=1;i<=m;i++)swap(nxt[a[i]],nxt[a[i]+1]);
    for(int i=1;i<=n;i++)ans[i]=i;
    while(K){
        if(K&1){
            for(int i=1;i<=n;i++)tmp[i]=ans[nxt[i]];
            for(int i=1;i<=n;i++)ans[i]=tmp[i];
        }
        for(int i=1;i<=n;i++)tmp[i]=nxt[nxt[i]];
        for(int i=1;i<=n;i++)nxt[i]=tmp[i];K>>=1;
    }
    for(int i=1;i<=n;i++)tmp[i]=X[ans[i]];
    for(int i=1;i<=n;i++)X[i]=tmp[i];int now=0;
    for(int i=1;i<=n;i++)now+=X[i],write(now);
    return 0;
}
