#include<bits/stdc++.h>
using namespace std;
int n,k,ans,tot;
int a[100005],b[100005];
struct Edge{
    int x,next;
}e[200005];
inline void pp(int x,int y){
    e[++tot].x=y;
    e[tot].next=a[x];
	a[x]=tot;
}
int dfs(int x,int deep){
    int ret=deep;
    for(int i=a[x];i;i=e[i].next)
        ret=max(ret,dfs(e[i].x,deep+1));
    if(b[x]!=1&&ret-deep==k-1)return ans++,0;
    else return ret;
}

int main(){
	int i;
    cin>>n>>k;
    for(i=1;i<=n;i++)scanf("%d",b+i);
    if(b[1]!=1)ans=b[1]=1;
    for(i=2;i<=n;i++)pp(b[i],i);
    dfs(1,0);
	cout<<ans;
	return 0;
}