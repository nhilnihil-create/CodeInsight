#include<cstdio>
#include<algorithm>
#define N 110000
using namespace std;
inline char gc(){
    static char now[1<<16],*T,*S;
    if (T==S){T=(S=now)+fread(now,1,1<<16,stdin);if (T==S) return EOF;}
    return *S++;
}
inline int read(){
    int x=0;char ch=gc();
    while (ch<'0'||ch>'9') ch=gc();
    while (ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=gc();}
    return x;
}
struct node{
    int y,next;
}data[N<<1];
struct node1{
    int dep,id;
}vect[N];
int h[N],fa[N],n,in[N],a[N],num;
void dfs(int x){
    for (int i=h[x];i;i=data[i].next){
        int y=data[i].y;if (fa[x]==y) continue;fa[y]=x;
        vect[y].dep=vect[x].dep+1;vect[y].id=y;
        if (in[y]==1) vect[y].dep=0;dfs(y);
    }
}
inline bool cmp(node1 a,node1 b){return a.dep>b.dep;}
int main(){
    n=read();
    for (int i=1;i<=n;++i) a[i]=read();
    if (n==2){if (a[1]==a[2]) printf("YES");else printf("NO");return 0;}
    for (int i=1;i<n;++i){
        int x=read(),y=read();
        data[++num].y=y;data[num].next=h[x];h[x]=num;in[y]++;
        data[++num].y=x;data[num].next=h[y];h[y]=num;in[x]++;
    }int root=1;while (in[root]==1) ++root;
    vect[root].dep=1;vect[root].id=root;dfs(root);
    sort(vect+1,vect+n+1,cmp);int op=1;
    while (vect[op].dep!=0){
        int x=vect[op++].id;long long ans1=0;int max1=0,child=0,childn=0;
        for (int i=h[x];i;i=data[i].next){
            int y=data[i].y;if (fa[x]==y) continue;
            ans1+=a[y];max1=max(max1,a[y]);child++;
        }if (a[x]>ans1){printf("NO");return 0;}
        if (child==1) if (ans1!=a[x]){printf("NO");return 0;}
        long long rest=ans1-max1;
        if (rest>=max1){
            if (ans1-a[x]>(ans1>>1)){printf("NO");return 0;}else a[x]-=ans1-a[x];
        }else{
            if (ans1-a[x]>rest){printf("NO");return 0;}else a[x]-=ans1-a[x];
        }
    }
    if (a[root]==0) printf("YES");else printf("NO");
    return 0;
}