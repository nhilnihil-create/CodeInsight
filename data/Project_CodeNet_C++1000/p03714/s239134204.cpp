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
const int maxn = 300000+10;
const int maxm = 200000+10;
const int mod = 1e9+7;
const double eps = 1e-9;
int a[maxn];
ll pre[maxn],suf[maxn];
multiset<int> s;
int main() {
#ifdef local
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n; cin>>n;
    ll sum=0;
    for (int i=1;i<=n*3;i++){
        cin>>a[i];
        if (i<=n) {
            sum+=a[i];
            s.insert(a[i]);
        } else {
            if (*s.begin()<a[i]){
                sum-=*s.begin();
                s.erase(s.begin());
                s.insert(a[i]);
                sum+=a[i];
            }
        }
        pre[i]=sum;
    }
    s.clear();
    sum=0;
    for (int i=3*n;i>=1;i--){
        if (i>2*n){
            sum+=a[i];
            s.insert(a[i]);
        } else {
            if (*s.rbegin()>a[i]){
                sum-=*s.rbegin();
                s.erase(--s.end());
                s.insert(a[i]);
                sum+=a[i];
            }
        }
        suf[i]=sum;
    }
    ll ans=-INF;
    for (int i=n;i<=2*n;i++){
        ans=max(ans,pre[i]-suf[i+1]);
    }
    cout<<ans<<"\n";
    return 0;
}
