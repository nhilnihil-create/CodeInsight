#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define ls rt<<1
#define rs rt<<1|1
typedef pair<int,int> pii;
const int maxn = 3e5 + 10;
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

inline ll sv(ll x) {
    ll ans=1;
    for(int i=1;i<=x;i++) {
        ans*=i;
        ans%=mod;
    }
    return ans;
}

int a[maxn];
ll pre[maxn],suf[maxn];
priority_queue<int> q;
int main() {
#ifdef LOCAL
    freopen("input.txt","r",stdin);
#endif // LOCAL
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    int n,m;
    n=read();
    m=n*3;
    for(int i=1;i<=m;i++) {
        a[i]=read();
    }
    ll sum=0;
    for(int i=1;i<=n;i++) {
        q.push(-a[i]);
        sum+=a[i];
    }
    pre[n]=sum;
    for(int i=n+1;i<=m-n;i++) {
        q.push(-a[i]);
        sum+=a[i];
        sum+=q.top();
        pre[i]=sum;
        q.pop();
    }
    while(!q.empty()) q.pop();
    sum=0;
    for(int i=m;i>m-n;i--) {
        q.push(a[i]);
        sum+=a[i];
    }
    suf[m-n+1]=sum;
    for(int i=m-n;i>n;i--) {
        q.push(a[i]);
        sum+=a[i];
        sum-=q.top();
        suf[i]=sum;
        q.pop();
    }
    ll ans=-INF;
    for(int i=n;i<=m-n;i++) {
        ans=max(ans,pre[i]-suf[i+1]);
    }
    cout<<ans;
    return 0;
}
//校园网真tm卡
