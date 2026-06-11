#include<cstdio>
#include<algorithm>
#define fo(i,a,b) for(i=a;i<=b;i++)
using namespace std;
const int maxm=100000+10,maxn=300000+10;
int tree[maxm],ans[maxm];
int h[maxm],go[maxm*20],nxt[maxm*20],ask[maxm*20][3];
int h2[maxm],g2[maxn],n2[maxn];
int i,j,k,l,t,n,m,tot,top;
void add(int x,int y){
    go[++tot]=y;
    nxt[tot]=h[x];
    h[x]=tot;
}
void add2(int x,int y){
    g2[++tot]=y;
    n2[tot]=h2[x];
    h2[x]=tot;
}
int lowbit(int x){
    return x&-x;
}
void change(int x){
    while (x){
        tree[x]++;
        x-=lowbit(x);
    }
}
int query(int x){
    int t=0;
    while (x<=m){
        t+=tree[x];
        x+=lowbit(x);
    }
    return t;
}
int main(){
    scanf("%d%d",&n,&m);
    fo(i,1,n){
        scanf("%d%d",&j,&k);
        add2(k,j);
    }
    tot=0;
    fo(i,1,m) ans[i]=n;
    fo(i,1,m){
        fo(j,1,m/i){
            ask[++top][0]=i*(j-1);
            ask[top][1]=i*j;
            ask[top][2]=i;
            add(ask[top][1],top);
        }
        top++;
        ask[top][0]=(m/i)*i;
        ask[top][1]=m+1;
        ask[top][2]=i;
        add(m+1,top);
    }
    fo(i,0,m+1){
        t=h[i];
        while (t){
            j=go[t];
            ans[ask[j][2]]-=query(ask[j][0]+1);
            t=nxt[t];
        }
        t=h2[i];
        while (t){
            change(g2[t]);
            t=n2[t];
        }
    }
    fo(i,1,m) printf("%d\n",ans[i]);
}