#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define fr(i,x,n) for(int i=x;i<=n;i++)
#define rf(i,n,x) for(int i=n;i>=x;i--)
#define mst(x,i) memset(x,i,sizeof(x))
#define IOS ios::sync_with_stdio(false),cin.tie(0)
#define MOD 1000000007
#define PB push_back
#define X first
#define Y second
using namespace std;
typedef long long LL;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int maxn=1E5+5;
const int maxm=3E5+5;
const int inf=0x3f3f3f3f;
const LL INF=0x3f3f3f3f3f3f3f3f;
const LL mod=998244353;
LL qpow(LL a,LL b){
    LL ret=1;
    while(b){
        if(b&1) ret*=a;
        a*=a;
        b>>=1;
    }
    return ret;
}
void solve(){
    LL x,y;cin>>x>>y;
    if(x<y) swap(x,y);
    LL t=x-y;
    if(t==1||t==0) cout<<"Brown"<<endl;
    else cout<<"Alice"<<endl;
}
int main(){
#ifdef LOCAL
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    IOS;
    int T;T=1;
    while(T--){
        solve();
    }
    return 0;
}
