#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define ls rt<<1
#define rs rt<<1|1
#define lb(x) (x&-x)
typedef pair<int,int> pii;
const int maxn = 4e5 + 10;
const int maxm = 1e6 + 10 ;
const int inf=0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const int st=(1<<20)-1;
const int mod = 1e9+7;
const double eps = 1e-5;
const int vec[2][2]={1,0,0,1};

inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
int f[maxn],n,m;
inline void add(int x,int p) {
    for(int i=x;i<=m;i+=lb(i)) f[i]+=p;
}
inline int ask(int r) {
    int ans=0;
    for(int i=r;i;i-=lb(i)) ans+=f[i];
    return ans;
}
ll pre[maxn],p[maxn];
int a[maxn];
int main() {
#ifdef LOCAL
    freopen("input.txt","r",stdin);
#endif // LOCAL
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    int k;
    n=read();
    k=read();
    for(int i=1;i<=n;i++) {
        a[i]=read();
        a[i]-=k;
    }
    for(int i=1;i<=n;i++) {
        pre[i]=pre[i-1]+a[i];
        p[++m]=pre[i];
    }
    p[++m]=0;
    sort(p+1,p+1+m);
    m=unique(p+1,p+1+m)-p-1;
    int pos=lower_bound(p+1,p+1+m,0)-p;
    ll ans=0;
    add(pos,1);
    for(int i=1;i<=n;i++) {
        pos=lower_bound(p+1,p+1+m,pre[i])-p;
        ans+=ask(pos);
        add(pos,1);
    }
    cout<<ans;
    return 0;
}
//校园网真tm卡
