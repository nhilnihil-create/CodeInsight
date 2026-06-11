#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MAX=100005;
const ll INF=0x3f3f3f3f;
const ll MOD=1000000007;
ll n,ans[MAX],pt,pt_idx=MAX;
pll a[MAX];
int main(){
    scanf(" %lld",&n);
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i].x),a[i].y=i;
    sort(a,a+n+1);
    for(ll i=n;i>=1;i--){
        pt_idx=min(pt_idx,a[i].y);
        ans[pt_idx]+=(n+1-i)*(a[i].x-a[i-1].x);
    }
    for(ll i=1;i<=n;i++) printf("%lld\n",ans[i]);
    return 0;
}
