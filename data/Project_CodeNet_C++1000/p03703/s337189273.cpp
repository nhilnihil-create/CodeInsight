#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mst(a,b) memset(a,b,sizeof(a))
#define lowbit(x) ((x)&(-x))
#define X first
#define Y second
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
typedef long long LL;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 200000+10;
const int maxm = 200000+10;
const int mod = 1e9+7;
const double eps = 1e-9;
int bit[maxn],tot;
void update(int pos,int val){
    for (;pos<=tot;pos+=lowbit(pos)) bit[pos]+=val;
}
int query(int pos){
    int res=0;
    for (;pos;pos-=lowbit(pos)) res+=bit[pos];
    return res;
}
ll x[maxn],s[maxn];
int get_id(ll val){
    return lower_bound(x+1,x+tot+1,val)-x;
}
int main() {
#ifdef local
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,k; cin>>n>>k;
    x[++tot]=0;
    for (int i=1;i<=n;i++){
        int v; cin>>v;
        s[i]=s[i-1]+v;
        x[++tot]=s[i]-1ll*i*k;
    }
    sort(x+1,x+tot+1);
    tot=unique(x+1,x+tot+1)-x-1;
    update(get_id(0),1);
    ll ans=0;
    for (int i=1;i<=n;i++){
        ll tmp=s[i]-1ll*i*k;
        ans+=query(get_id(tmp));
        update(get_id(tmp),1);
    }
    cout<<ans<<"\n";
    return 0;
}
