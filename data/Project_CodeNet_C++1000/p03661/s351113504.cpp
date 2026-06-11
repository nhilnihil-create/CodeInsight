#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MAX=209999;
const ll INF=0x3f3f3f3f3f3f3f;
ll n,a[MAX],p,q,ans=INF;
int main()
{
    scanf("%lld",&n);
    for(ll i=0;i<n;i++) scanf("%lld",&a[i]),p+=a[i];
    q=a[0],p-=a[0];
    for(ll i=1;i<n;i++){
        ans=min(ans,abs(p-q));
        p-=a[i],q+=a[i];
    }
    printf("%lld\n",ans);
    return 0;
}
