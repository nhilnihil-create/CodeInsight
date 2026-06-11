#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mst(a,b) memset(a,b,sizeof(a))
#define lowbit(x) ((x)&(-x))
#define X first
#define Y second
#define lc o<<1
#define rc o<<1|1
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
const int maxm = 2000+10;
const int mod = 1e9+7;
const double eps = 1e-8;
int a[maxn];
int main() {
#ifdef local
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n; cin>>n;
    ll sum=0;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    ll ans=INF,s=0;
    for (int i=1;i<n;i++){
        s+=a[i];
        ans=min(ans,abs(sum-s-s));
    }
    cout<<ans<<"\n";
    return 0;
}
