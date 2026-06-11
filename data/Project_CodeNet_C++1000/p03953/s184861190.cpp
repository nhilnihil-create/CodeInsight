#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
typedef long long ll;
int gi() {
    int x=0,o=1;char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
    if(ch=='-') o=-1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*o;
}
int n,m,id[N],st[N],top=0;
ll a[N],ans[N],k;
bool vis[N];
int main() {
	//freopen("rabbit.in","r",stdin);
	//freopen("rabbit.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) a[i]=gi(),id[i]=i;
    for(int i=n;i;i--) a[i]-=a[i-1];
    cin>>m>>k;
    for(int i=1,x;i<=m;i++) x=gi(),swap(id[x],id[x+1]);
    for(int i=1;i<=n;i++)
        if(!vis[i]) {
            top=0;
            for(int j=i;!vis[j];j=id[j]) st[++top]=j,vis[j]=1;
            for(int j=1;j<=top;j++) ans[st[j]]=a[st[(k+j-1)%top+1]];
        }
    for(int i=1;i<=n;i++) ans[i]+=ans[i-1],printf("%lld\n",ans[i]);
    return 0;
}