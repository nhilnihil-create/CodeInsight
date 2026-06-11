#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;

#define dbg(x1) cout<<#x1<<" = "<<(x1)<<endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<(x1)<<" "<<#x2<<" = "<<(x2)<<endl
#define dbg3(x1,x2,x3) cout<<#x1<<" = "<<(x1)<<" "<<#x2<<" = "<<(x2)<<" "<<#x3<<" = "<<(x3)<<endl
int h[maxn];
ll cal(ll a,ll b)
{
    return a/b + (a%b!=0);
}
int n,a,b;
bool check(ll mid)
{
    ll ned=0;
    for(int i=1;i<=n;i++)
    {
        if(cal(h[i],b)<=mid) continue;
        else
        {
            ll tt = h[i] - 1LL*mid*b;
            ned += cal(tt,a-b);
        }
        if(ned>mid) return false;
    }
    return ned<=mid;
}
int main() {
    //freopen(".in", "r", stdin);
    scanf("%d%d%d",&n,&a,&b);
    for(int i=1;i<=n;i++) scanf("%d",&h[i]);
    ll l=1,r=100000000000000LL;
    while(l<=r)
    {
        ll mid=(l+r)>>1;
        if(check(mid)) r=mid-1;
        else l=mid+1;
    }
    printf("%lld\n",l);
    return 0;
}

