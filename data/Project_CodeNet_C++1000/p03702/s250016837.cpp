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
const int maxn = 100000+10;
const int maxm = 200000+10;
const int mod = 1e9+7;
const double eps = 1e-9;
int a[maxn],n,A,B;
bool check(int x){
    ll res=0;
    for (int i=0;i<n;i++){
        if (a[i]>1ll*x*B){
            res+=(a[i]-x*B+A-1)/A;
        }
    }
    return res<=x;
}
int main() {
#ifdef local
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>A>>B;
    A-=B;
    for (int i=0;i<n;i++) cin>>a[i];
    int L=0,R=1e9,ans;
    while (L<=R){
        int mid=L+(R-L)/2;
        if (check(mid)){
            ans=mid;
            R=mid-1;
        } else {
            L=mid+1;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
