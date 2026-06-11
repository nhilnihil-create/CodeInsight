#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define MAXN 300005
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
int n,m,sum[MAXN];
struct node{
    int l,r;
}a[MAXN];
vector<int>v[MAXN];
int lowbit(int x){
    return x&-x;
}
void add(int x,int y){
    while(x<=m){
        sum[x]+=y;
        x+=lowbit(x);
    }
}
int query(int x){
    int ans=0;
    while(x){
        ans+=sum[x];
        x-=lowbit(x);
    }
    return ans;
}
int main(){
    while(~scanf("%d%d",&n,&m)){
        memset(sum,0,sizeof(sum));
        rep(i,1,m){
            v[i].clear();
        }
        rep(i,1,n){
            scanf("%d%d",&a[i].l,&a[i].r);
            int temp=a[i].r-a[i].l+1;
            v[temp].push_back(i);
        }
        rep(i,1,m){
            int ans=0,len=v[i].size();
            rep(j,0,len-1){
                int pos=v[i][j];
                add(a[pos].l,1);
                add(a[pos].r+1,-1);
            }
            for(int j=i;j<=m;j+=i){
                ans+=query(j);
            }
            n-=len;
            printf("%d\n",ans+n);
        }
    }
    return 0;
}