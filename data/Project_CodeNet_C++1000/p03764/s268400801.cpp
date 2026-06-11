#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MAX=500005;
const ll INF=0x3f3f3f3f;
const ll MOD=1000000007;
ll n,m,a[MAX],a_sum[MAX],b[MAX],b_sum[MAX],s1,s2;
int main(){
    scanf("%lld%lld",&n,&m);
    for(ll i=0;i<n;i++) scanf("%lld",&a[i]),a_sum[i+1]=(a_sum[i]+a[i])%MOD;
    for(ll i=0;i<m;i++) scanf("%lld",&b[i]),b_sum[i+1]=(b_sum[i]+b[i])%MOD;
    sort(a,a+n),sort(b,b+m);
    for(ll i=0;i<n;i++) s1=(s1+i*a[i]-a_sum[i])%MOD;
    for(ll i=0;i<m;i++) s2=(s2+i*b[i]-b_sum[i])%MOD;
    printf("%lld\n",s1*s2%MOD);

    return 0;
}
